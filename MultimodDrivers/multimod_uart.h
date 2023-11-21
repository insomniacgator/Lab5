// multimod_uart.h
// Date Created: 2023-07-25
// Date Updated: 2023-07-27
// UART header file

#ifndef MULTIMOD_UART_H_
#define MULTIMOD_UART_H_

/************************************Includes***************************************/

#include <stdint.h>
#include <stdbool.h>

#include <driverlib/uartstdio.h>

/************************************Includes***************************************/

/*************************************Defines***************************************/
// 16 MHz / 10 = 0.1 s
#define delay_0_1_s     1600000
#define UART0_CLK       16000000
#define BAUDRATE        115200
/*************************************Defines***************************************/

/******************************Data Type Definitions********************************/
/******************************Data Type Definitions********************************/

/****************************Data Structure Definitions*****************************/
/****************************Data Structure Definitions*****************************/

/***********************************Externs*****************************************/
/***********************************Externs*****************************************/

/********************************Public Variables***********************************/
/********************************Public Variables***********************************/

/********************************Public Functions***********************************/

void UART_Init();

/********************************Public Functions***********************************/

/*******************************Private Variables***********************************/
/*******************************Private Variables***********************************/

/*******************************Private Functions***********************************/
/*******************************Private Functions***********************************/

#endif /* MULTIMOD_UART_H_ */


