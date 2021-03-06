/* #include "module_rs232.h" */

#ifndef __MODULE_RS232_H
#define __MODULE_RS232_H

#include "stm32f4xx.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void RS232_Config( void );
void RS232_Print( USART_TypeDef*, u8* );
void RS232_VisualScope( USART_TypeDef*, u8*, u16 );
/*=====================================================================================================*/
/*=====================================================================================================*/
#endif
