/**
  ******************************************************************************
  * @file    App/main.c 
  * @author  Windy Albert
  * @version V1.0.0
  * @date    27-January-2023
  * @brief   Main program body
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Public variables ----------------------------------------------------------*/
uint32_t SysTime = 0;
extern uint32_t Image$$INIT_TBL$$Base;
extern uint32_t Image$$INIT_TBL$$Limit;
extern uint32_t Image$$PROC_TBL$$Base;
extern uint32_t Image$$PROC_TBL$$Limit;

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    init_fnc_t *init_fnc;
    process_fnc_t *proc_fnc;
    
	__disable_irq();
    
    /* SysTick end of count event each 1ms */
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
    
    for( init_fnc = (init_fnc_t*)&Image$$INIT_TBL$$Base;                \
         init_fnc < (init_fnc_t*)&Image$$INIT_TBL$$Limit;               \
         init_fnc ++ )
    {
        if( (*init_fnc)() )
        {
            while(1);
        }
    }
    __enable_irq();
    
    for(;;)
    {
        for( proc_fnc = (process_fnc_t*)&Image$$PROC_TBL$$Base;         \
             proc_fnc < (process_fnc_t*)&Image$$PROC_TBL$$Limit;        \
             proc_fnc ++ )
        {
            (*proc_fnc)();
        }        
    }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    SysTime++;
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
