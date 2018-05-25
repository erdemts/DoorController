/*******************************************************************************
 *
 * FileName     : BusIdDongle main.c
 * Dependencies :
 * Description  :
 * Processor    : PIC16F887
 * Compiler     : Hi-tech Picc 9.83
 * Linker       :
 * Company      : Inno Technology Incorporated
 *
 * Software License Agreement
 * Copyright (C) 2011 - 2012 Inno Technology Inc.  All rights
 * reserved.
 *
 * Version    Author                     Date             Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 1.0        Erdem Tayfun Salman       11/14/2014       Initial Version
 ******************************************************************************/
//KAPI 1 ACIKKEN 0, KAPALIYKEN 24V
//DIGER KAPILAR: ACIKKEN 24V, KAPALIYKEN 0

#include "includes.h"

__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_ON & PWRTE_ON & MCLRE_ON & CP_ON & CPD_ON & BOREN_ON & IESO_OFF & FCMEN_OFF & LVP_OFF & DEBUG_OFF & BOR4V_BOR40V );


#define SM_IDLE                             0
#define SM_SEND_DATA                        1
#define SM_WAIT_ACK                         2
#define SM_WAIT_DATA                        3
#define SM_WAIT_ETX                         4
#define SM_CMD_READY                        5
#define true                                1
#define false                               0
#define ACK                                 'A'

#define DEBOUNCE                            100



/* DEFINE LOCAL TYPES HERE ---------------------------------------------------*/
/* DEFINE LOCAL MACROS HERE --------------------------------------------------*/
#define bit_set(var,bitno)      ((var) |= 1 << (bitno))
#define bit_clear(var,bitno) 	((var) &= ~(1 << (bitno)))
#define bit_test(data,bitno) 	((data>>bitno)&0x01)
#define bit_test_int(data,bitno) 	((data>>bitno)&0x0001)
#define hibyte(x)		(unsigned char)	((x>>8) & 0xFF)
#define lobyte(x)		(unsigned char)	(x & 0xFF)

/* DEFINE LOCAL VARIABLES HERE -----------------------------------------------*/
volatile unsigned char doorStates = 0;
volatile unsigned char ackComplated = 0;
volatile unsigned char doorStatesChanged = 0;

volatile unsigned char tick250ms;
volatile unsigned char timeOutCounter;
volatile unsigned char timeOutTimer;
bit timeOutFlag;
volatile unsigned char uartState = 0;


volatile unsigned char door1State = 0;
volatile unsigned char door2State = 0;
volatile unsigned char door3State = 0;
volatile unsigned char door4State = 0;
/* DECLARE EXTERNAL VARIABLES HERE -------------------------------------------*/
/* DECLARE LOCAL FUNCTIONS HERE ----------------------------------------------*/
void vInitializeBoard(void);
void vDelay( void );
void setTimeOut( unsigned char timeOut );


/* DEFINE FUNCTIONS HERE -----------------------------------------------------*/
/* DEFINE LOCAL FUNCTIONS HERE -----------------------------------------------*/



/*******************************************************************************
 *
 * Function     :
 * PreCondition : None
 * Input        : None
 * Output       : None
 * Side Effects : None
 * Overview     :
 * Note         : None
 *
 ******************************************************************************/
main(void)
{
    unsigned char sayi = 0;
    vInitializeBoard();
    vInitializeUart();
    PEIE = 1;
    ei();
    doorStatesChanged = false;
    door1State = DOOR_1;
    door2State = DOOR_2;
    door3State = DOOR_3;
    door4State = DOOR_4;
    
    LED_RED = 1;
   
    
    while(1)
    {
        CLRWDT();

        if(doorStatesChanged == true)
        {
            doorStatesChanged = false;
            uartState = SM_SEND_DATA;
            LED_GREEN ^= 1;
        }

        if(uartState == SM_SEND_DATA)
        {
            //KAPI 1 ACIKKEN 24V, KAPALIYKEN 0
            //DIGER KAPILAR: ACIKKEN 0, KAPALIYKEN 24V
            uartState = SM_WAIT_ACK;
            setTimeOut(150);
            if(bit_test(doorStates,0))
            {
                putch('1');
            }
            else
            {
                putch('0');
            }
            if(bit_test(doorStates,1))
            {
                putch('1');
            }
            else
            {
                putch('0');
            }
            if(bit_test(doorStates,2))
            {
                putch('1');
            }
            else
            {
                putch('0');
            }
            if(bit_test(doorStates,3))
            {
                putch('1');
            }
            else
            {
                putch('0');
            }
            
        }
    }	
}



void interrupt erdem(void)
{
    unsigned char temp;
    unsigned int i;

    if(T0IE && T0IF)
    {
        ++timeOutTimer;
        if((timeOutTimer == timeOutCounter) && timeOutFlag)
        {
            timeOutTimer = 0;

            if(uartState == SM_WAIT_ACK)
            {
                uartState = SM_SEND_DATA;
            }

        }
        T0IF = 0;
        return;
    }
    if(RBIE && RBIF)
    {
        vDelay();
        
        if(doorStates != (PORTB & 0x0F))
        {
            __delay_ms(40);
            __delay_ms(40);
            __delay_ms(40);
            __delay_ms(40);
            __delay_ms(40);
            __delay_ms(40);
//            __delay_ms(40);
            if(doorStates != (PORTB & 0x0F))
            {
                doorStatesChanged = true;
                doorStates = (PORTB & 0x0F);
            }
        }
        
        PORTB;
        RBIF = 0;
        vDelay();
        return;
    }
		
    if(RCIE && RCIF)
    {
        if (OERR)
        {
            CREN=0;
            CREN=1;
        }
        if(FERR)
        {
            temp = RCREG;
        }
        while(!RCIF)
        {
            vCheckError();
        }
        
        temp = RCREG;
        if(temp == ACK)
        {
            uartState = SM_IDLE;
        }
        else if(temp == 'P')
        {
            __delay_ms(5);
            putch('H');
        }
        return;
    }

   
		

}



/*******************************************************************************
 *
 * Function     : void vInitializeBoard(void)
 * PreCondition : None
 * Input        : None
 * Output       : None
 * Side Effects : None
 * Overview     :
 * Note         : None
 *
 ******************************************************************************/
void vInitializeBoard(void)
{
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;


    CM1CON0 = 0;
    CM2CON0 = 0;
    OSCCON  = 0b01110101;

    C1ON = 0;
    C2ON = 0;

    WDTCON = 0b00010111;
    OPTION_REG	= 0b10000111; //pull ups disable TMR0 prescaler 1:256

    ANSELH = 0;
    ANSEL = 0;

    T0IF = 0;
    T0IE = 1;

    TRISA = 0b00000000; //
    TRISB = 0b00001111; //
    TRISC = 0b11000100; //
    TRISD = 0b00000000; //
    TRISE = 0b00000000; //

    IOCB = 0b00001111;  //Portb 0-3 için interrupt on change aktif edilmistir
    PORTB;
    RBIF = 0;
    RBIE = 1;

    doorStates = (PORTB & 0x0F);

}
    /*******************************************************************************
 *
 * Function     : void vDelay( void )
 * PreCondition : None
 * Input        : None
 * Output       : None
 * Side Effects : None
 * Overview     :
 * Note         : None
 *
 ******************************************************************************/
void vDelay( void )
{
    unsigned int i;
    for( i = 0; i < 5000; i++ )
    {
        NOP();
    }
}


void setTimeOut( unsigned char timeOut )
{
    timeOutTimer = 0;
    timeOutCounter = timeOut;
    timeOutFlag = 1;
}
