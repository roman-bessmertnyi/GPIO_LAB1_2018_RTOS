/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/


#include <stm32f10x.h>                       /* STM32F103 definitions         */

///*----------------------------------------------------------------------------
//  wait function 1
// *----------------------------------------------------------------------------*/
//void wait (void)  {
//  int  d;

//  for (d = 0; d < 2000000; d++);             /* only to delay for LED flashes */
//}
///*----------------------------------------------------------------------------
//  wait function 2
// *----------------------------------------------------------------------------*/
//void Delay(__IO uint32_t nCount)
//{
//  for(; nCount != 0; nCount--);
//}

///*----------------------------------------------------------------------------
//  wait function 3
// *----------------------------------------------------------------------------*/

//volatile uint32_t msTicks;

//void SysTick_Handler (void) //Enter here every 1 ms
//{
//  msTicks++;
//}


// struct MyStruct
//{
//int field;
//}*sfdf;

//typedef struct MyStruct1
//{
//int field;
//}*sfdf1;

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
#define BSRR_VAL        0x0300

void delay (int a);



int main (void) {
//struct MyStruct ttest;
//    ttest.field = 12;
//    sfdf->field=77;
// // MyStruct1 r;

  RCC->APB2ENR |= (1UL << 3);                /* Enable GPIOB clock            */
  GPIOB->CRH    =  0x33333333;               /* PB.8..16 defined as Outputs   */

  while (1)  {                               /* Loop forever                  */
    
    GPIOB->BSRR = BSRR_VAL;                       /* Set PВ8 and PВ9 */
    delay(1000);
                         
    GPIOB->BRR = BSRR_VAL;                         /* Turn LED off*/
    delay(1000);  //610.5 KHz 
      // 473,7 
     // 21 
        //1.64 mks                
  }
}


void delay (int a)
{
    volatile int i,j;

    for (i=0 ; i < a ; i++)
    {
        j++;
    }

    return;
}


