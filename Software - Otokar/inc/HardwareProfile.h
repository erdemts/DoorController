/*******************************************************************************
 *
 * FileName     : HardwareProfile.h ( DoorController Hardware profile file )
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
 * 1.0        Erdem Tayfun Salman       01/09/2015       Initial Version
 ******************************************************************************/
#ifndef HARDWAREPROFILE_H
#define HARDWAREPROFILE_H

#include <htc.h>

#define _XTAL_FREQ	8000000





/*****************************************************************************
 *	I/O Pins
 *****************************************************************************/
#define LED_RED                 (PORTDbits.RD0) //RED LED
#define LED_RED_TRIS		(TRISDbits.TRISD0) //RED LED

#define LED_GREEN               (PORTDbits.RD1) //GREEN LED
#define LED_GREEN_TRIS          (TRISDbits.TRISD1) //GREEN LED




/*****************************************************************************
 *	Uart
 *****************************************************************************/
#define UARTTX_TRIS	(TRISCbits.TRISC6)
#define UARTRX_TRIS	(TRISCbits.TRISC7)

/*****************************************************************************
 *	Inputs
 *****************************************************************************/
#define DOOR_1_TRIS     (TRISBbits.TRISB0)
#define DOOR_1          (PORTBbits.RB0)

#define DOOR_2_TRIS     (TRISBbits.TRISB1)
#define DOOR_2          (PORTBbits.RB1)

#define DOOR_3_TRIS     (TRISBbits.TRISB2)
#define DOOR_3          (PORTBbits.RB2)

#define DOOR_4_TRIS     (TRISBbits.TRISB3)
#define DOOR_4          (PORTBbits.RB3)

#define SPEED_INPUT_TRIS    (TRISCbits.TRISC2)
#define SPEED_INPUT     (PORTCbits.RC2)



#endif
