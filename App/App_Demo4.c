/**
  ******************************************************************************
  * @file    App/App_Demo4.c
  * @author  Windy Albert
  * @version V1.0.0
  * @date    2024-01-06
  * @brief   Demo4 application program.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "App_Demo4.h"

/* Public variables ----------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static CTimer runTimer(100);
/* Private functions ---------------------------------------------------------*/
#define TIME_CNT_STOP   (0x80000000)
#define TIME_CNT_IDLE   (0xffffffff)

#define TASK_START_SIGNAL   (1)

#define SECOND_SIGNAL       (1)

#define ERROR_SIGNAL        (1)

/**
  * @brief  App init program
  * @param  None
  * @retval 0 for success, other for error.
  */
INIT_REG_LEVEL_3(Demo4_init)
{
    /* Replace your code with this line. */

    return 0;
}

/**
  * @brief  App loop process program
  * @param  None
  * @retval None
  */
PROCESS_REG(Demo4_process)
{
    static uint32_t timeCnt = 0;
    
    if(runTimer.TimeOut())
    {    
        if(!(timeCnt&TIME_CNT_STOP))
        {
            timeCnt++;
        }
        
        switch (timeCnt)
        {
            case TIME_CNT_IDLE:
                if(TASK_START_SIGNAL)
                {
                    timeCnt = 0;
                }
                break;
            
            case  600:  /* 1 min */
                /* do sth */
                break;
            
            case 1200:  /* 2 min */
                /* do sth */
                
                timeCnt |= TIME_CNT_STOP;
                break;
            case 1200|TIME_CNT_STOP:
                if(SECOND_SIGNAL)
                {
                    /* do sth */
                    
                    timeCnt &= ~TIME_CNT_STOP;
                }
                break;
            
            case 6000:  /* 10 min */
                timeCnt = TIME_CNT_IDLE;
                break;
            
            default:
                break;        
        }
        
        if(ERROR_SIGNAL)
        {
            /* do sth */
            
            timeCnt = TIME_CNT_IDLE;
        }        
    }    
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
