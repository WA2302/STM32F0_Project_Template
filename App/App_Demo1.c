/**
  ******************************************************************************
  * @file    App/App_Demo1.c
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2024-01-06
  * @brief   Demo1 application program.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "App_Demo1.h"

/* Public variables ----------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static CTimer runTimer(500);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  App init program
  * @param  None
  * @retval 0 for success, other for error.
  */
INIT_REG_LEVEL_3(Demo1_init)
{
    /* Replace your code with this line. */

    return 0;
}

/**
  * @brief  App loop process program
  * @param  None
  * @retval None
  */
PROCESS_REG(Demo1_process)
{
    if(runTimer.TimeOut())
    {
        // do sth each 500ms.
    }    
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
