/*******************************************************************************
 * 
 * FileName     : 
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
#ifndef _COMMANDS_H
#define _COMMANDS_H

// Sample UART message package
// <STX> <CMD> <ETX> or <STX> <CMD> <DATA> <ETX>, CMD and all datas must be in ASCII format.
// 1BYTE 1BYTE 1BYTE    1BYTE 1BYTE 8BYTE  1BYTE
//
// <0x02><'A'><0x03> or <0x02><'A'><DATA(max 8 byte)><0x03>
//
// MAX Data size is 8 Bytes.
// STX = 0x02
// ETX = 0x03

/*****************************************************************************
 *	KOMUTLAR
 * All commands and datas must be in ASCII format.
 * <STX> <CMD_SET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ISI_DEGERI(3 byte (örne?in 023)> <ETX>
 * <STX> <CMD_GET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ETX>
 * <STX> <CMD_SET_FAN_GROUP> <GROUP_NO(1-8)> <FAN1(1/0)><FAN2(1/0)><FAN3(1/0)><FAN4(1/0)><FAN5(1/0)><FAN6(1/0)><FAN7(1/0)><FAN8(1/0)><FAN9(1/0)><FAN10(1/0)><FAN11(1/0)><FAN12(1/0)> <ETX>
 * <STX> <CMD_GET_FAN_GROUP> <GROUP_NO(1-8)> <ETX>
 * <STX> <CMD_GET_CURRENT_TEMPERATURE> <ISI_DEGERI(3 byte (örne?in 023)> <ETX>
 * <STX> <CMD_LCD_POWER_ON> <ETX>
 * <STX> <CMD_LCD_POWER_OFF> <<ETX>
 * <STX> <CMD_GET_SERIAL_NO> <ETX>
 * <STX> <CMD_SET_SERIAL_NO> <8byte SERIAL NO> <ETX>
 * <STX> <CMD_GET_LCD_STATUS> <ETX>
 *****************************************************************************/


//PC to Dongle Messages
#define CMD_SET_TEMP_LEVEL              ('A')
#define CMD_GET_TEMP_LEVEL              ('B')
#define CMD_GET_SERIAL_NO               ('C')
#define CMD_SET_SERIAL_NO               ('D')
#define CMD_SET_FAN_GROUP               ('E')
#define CMD_GET_FAN_GROUP               ('F')
#define CMD_GET_CURRENT_TEMPERATURE     ('G')
#define CMD_LCD_POWER_ON                ('H')
#define CMD_LCD_POWER_OFF               ('I')
#define CMD_GET_LCD_STATUS              ('J')
#define CMD_SET_CURRENT_TEMPERATURE     ('K')//DEBUG ONLY
#define CMD_SET_DEBUG_MODE              ('L')


//Dongle to PC Responses
#define RSP_SET_TEMP_LEVEL              ('N')
#define RSP_GET_TEMP_LEVEL              ('O')
#define RSP_GET_SERIAL_NO               ('P')
#define RSP_SET_SERIAL_NO               ('R')
#define RSP_SET_FAN_GROUP               ('S')
#define RSP_GET_FAN_GROUP               ('T')
#define RSP_GET_CURRENT_TEMPERATURE     ('U')
#define RSP_LCD_POWER_ON                ('V')
#define RSP_LCD_POWER_OFF               ('Y')
#define RSP_GET_LCD_STATUS              ('Z')
#define RSP_SET_CURRENT_TEMPERATURE     ('X')//DEBUG ONLY
#define RSP_SET_DEBUG_MODE              ('W')


//------------------------------------------------------------------------------------
//#define CMD_SET_TEMP_LEVEL              ('A')
//<STX> <CMD_SET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ISI_DEGERI(3 byte (örne?in 023)> <ETX>
//0x02 A 1 090 0x03  Set temp level 1 to 90 degree celcius
//#002A1090#003 Set temp level 1 to 90 degree celcius
//#002A2080#003 Set temp level 2 to 80 degree celcius
//#002A3070#003
//#002A4060#003
//#002A5050#003
//#002A6040#003
//#002A7030#003
//#002A8020#003
//
//Response
//#define RSP_SET_TEMP_LEVEL              ('N')
//<STX> <RSP_SET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ISI_DEGERI(3 byte (örne?in 023)> <ETX>
//0x02 N 1 090 0x03 Response for Set temp level 1 to 90 degree celcius command

//------------------------------------------------------------------------------------

//#define CMD_GET_TEMP_LEVEL              ('B')
//<STX> <CMD_GET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ETX>
//0x02 B 1 0x03 Get Temperature Level 1
//#002B1#003
//#002B2#003
//#002B3#003
//#002B4#003
//#002B5#003
//#002B6#003
//#002B7#003
//#002B8#003
//
//Response
//#define RSP_GET_TEMP_LEVEL              ('O')
//<STX> <RSP_GET_TEMP_LEVEL> <LEVEL_NO(1-8)> <ISI_DEGERI(3 byte (örne?in 023)> <ETX>
//0x02 O 1 090 0x03 Get Temperature Level 1

//------------------------------------------------------------------------------------

//#define CMD_GET_SERIAL_NO               ('C')
//<STX> <CMD_GET_SERIAL_NO> <ETX>
//0x02 C 0x03
//#002C#003
//
//Response
//#define RSP_GET_SERIAL_NO               ('P')
//<STX> <RSP_GET_SERIAL_NO> <SERIAL NO 8 Byte> <ETX>
//0x02 P S1 S2 S3 S4 S5 S6 S7 S8 0x03

//------------------------------------------------------------------------------------

//#define CMD_SET_SERIAL_NO               ('D')
//<STX> <CMD_SET_SERIAL_NO> <ETX>
//0x02 D S1 S2 S3 S4 S5 S6 S7 S8 0x03
//#002D12345678#003
//
//Response
//#define RSP_SET_SERIAL_NO               ('R')
//<STX> <RSP_SET_SERIAL_NO> <SERIAL NO 8 Byte> <ETX>
//0x02 P S1 S2 S3 S4 S5 S6 S7 S8 0x03

//------------------------------------------------------------------------------------

//#define CMD_SET_FAN_GROUP               ('E')
//<STX> <CMD_SET_FAN_GROUP> <GROUP_NO(1-8)> <FAN1(1/0)><FAN2(1/0)><FAN3(1/0)><FAN4(1/0)><FAN5(1/0)><FAN6(1/0)>
//                                          <FAN7(1/0)><FAN8(1/0)><FAN9(1/0)><FAN10(1/0)><FAN11(1/0)><FAN12(1/0)> <ETX>
//0x02 E 1 1 1 1 1 1 1 1 1 1 1 1 1 0x03   Activate all fans for Fan Group 1
//#002E1111111111111#003
//#002E2011111111110#003
//#002E3001111111100#003
//#002E4000111111000#003
//#002E5000011110000#003
//#002E6000001100000#003
//#002E7100000000001#003
//#002E8110000000011#003
//
//Response
//#define RSP_SET_SERIAL_NO               ('R')
//<STX> <CMD_SET_FAN_GROUP> <GROUP_NO(1-8)> <FAN1(1/0)><FAN2(1/0)><FAN3(1/0)><FAN4(1/0)><FAN5(1/0)><FAN6(1/0)>
//                                          <FAN7(1/0)><FAN8(1/0)><FAN9(1/0)><FAN10(1/0)><FAN11(1/0)><FAN12(1/0)> <ETX>
//0x02 R 1 1 1 1 1 1 1 1 1 1 1 1 1 0x03

//------------------------------------------------------------------------------------

//#define CMD_GET_FAN_GROUP               ('F')
//<STX> <CMD_SET_FAN_GROUP> <GROUP_NO(1-8)> <ETX>
//0x02 F 1 0x03
//#002F1#003
//#002F2#003
//#002F3#003
//#002F4#003
//#002F5#003
//#002F6#003
//#002F7#003
//#002F8#003
//
//Response
//#define RSP_GET_FAN_GROUP               ('T')
//<STX> <RSP_GET_FAN_GROUP> <GROUP_NO(1-8)> <FAN1(1/0)><FAN2(1/0)><FAN3(1/0)><FAN4(1/0)><FAN5(1/0)><FAN6(1/0)>
//                                          <FAN7(1/0)><FAN8(1/0)><FAN9(1/0)><FAN10(1/0)><FAN11(1/0)><FAN12(1/0)> <ETX>
//0x02 T 1 1 1 1 1 1 1 1 1 1 1 1 1 0x03

//------------------------------------------------------------------------------------

//#define CMD_GET_CURRENT_TEMPERATURE     ('G')
//<STX> <CMD_GET_CURRENT_TEMPERATURE> <ISI_DEGERI(3 byte (örnegin 023)> <ETX>
//0x02 G 0x03
//#002G#003
//
//Response
//#define RSP_GET_CURRENT_TEMPERATURE     ('U')
//<STX> <RSP_GET_CURRENT_TEMPERATURE> <ISI_DEGERI(3 byte (örnegin 023)> <ETX>
//0x02 U 030 0x03

//------------------------------------------------------------------------------------

//#define CMD_LCD_POWER_ON                ('H')
//<STX> <CMD_LCD_POWER_ON> <ETX>
//0x02 H 0x03
//#002H#003
//
//Response
//#define RSP_LCD_POWER_ON                ('V')
//<STX> <RSP_LCD_POWER_ON> <LCD_STATUS(1/0)> <ETX>
//0x02 V 1 0x03

//------------------------------------------------------------------------------------

//#define CMD_LCD_POWER_OFF               ('I')
//<STX> <CMD_LCD_POWER_OFF> <ETX>
//0x02 I 0x03
//#002I#003
//
//Response
//#define RSP_LCD_POWER_OFF               ('Y')
//<STX> <RSP_LCD_POWER_OFF> <LCD_STATUS(1/0)> <ETX>
//0x02 Y 1 0x03

//------------------------------------------------------------------------------------

//#define CMD_GET_LCD_STATUS              ('J')
//#define CMD_SET_CURRENT_TEMPERATURE              ('K')//DEBUG ONLY
//0x02 J 0x03
//#002J#003
//
//Response
//#define RSP_GET_LCD_STATUS              ('Z')
//<STX> <RSP_GET_LCD_STATUS> <LCD_STATUS(1/0)> <ETX>
//0x02 Z 1 0x03



//DEBUG modda iken cihaza CMD_SET_CURRENT_TEMPERATURE komutu ile ölçülen isi degerini simule etmesi istenen isi degeri yollanabilir. Bu özellik testler için kullanilir.
//Ayarlanan isi degerlerinde hangi fanlarin çalistiginin görülmesi için DEBUG modda istenen isi degerleri gönderilir.
//DEBUG modda iken D18 ledi devamli olarak yanip soner. Normal çalismaya geçirmek için mutlaka  <STX> <CMD_SET_DEBUG_MODE> <0> <ETX> komutu gönderilmelidir.
//DEBUG modda kapanan cihaz, DEBUG modda açilir. 


//------------------------------------------------------------------------------------

//#define CMD_SET_CURRENT_TEMPERATURE              ('K')//DEBUG ONLY
//0x02 K 0x10 0x03
//#002K#090#003

//------------------------------------------------------------------------------------

//#define CMD_SET_DEBUG_MODE              ('L')
//<STX> <CMD_SET_DEBUG_MODE> <1/0> <ETX>
//0x02 L 1 0x03 //active debug mode
//#002L1#003
//
//Response
//#define RSP_SET_DEBUG_MODE              ('W')
//<STX> <RSP_LCD_POWER_OFF> <LCD_STATUS(1/0)> <ETX>
//





#endif	
