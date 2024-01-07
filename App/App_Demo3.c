/**
  ******************************************************************************
  * @file    App/App_Demo3.c
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2024-01-06
  * @brief   Demo3 application program.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "App_Demo3.h"

/* Public variables ----------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static CTimer runTimer(2000);
/* Private functions ---------------------------------------------------------*/

#define STH_IS_READY    (1)

/**
  * @brief  App init program
  * @param  None
  * @retval 0 for success, other for error.
  */
INIT_REG_LEVEL_3(Demo3_init)
{
    /* Replace your code with this line. */

    return 0;
}

/**
  * @brief  App loop process program
  * @param  None
  * @retval None
  */
PROCESS_REG(Demo3_process)
{
    if(STH_IS_READY)
    {
        // do sth when STH is ready
    }
    else if(runTimer.TimeOut())
    {
        // do sth when timeout
    }    
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
