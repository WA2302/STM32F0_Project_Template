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
#define GPO_H(x,n) GPIO##x->BSRR = GPIO_Pin_##n; 
#define GPO_L(x,n) GPIO##x->BRR  = GPIO_Pin_##n;                    
#define GPO_Z(x,n) \
	if( GPIO##x->ODR & GPIO_Pin_##n )   GPIO##x->BRR  = GPIO_Pin_##n; \
	else                         		GPIO##x->BSRR = GPIO_Pin_##n;  

#define GPI_X(x,n) ( GPIO##x->IDR & GPIO_Pin_##n )



#define RED_ON() 		GPO_H(B,1)
#define RED_OFF() 		GPO_L(B,1)

#define RED_BLING() 	GPO_Z(B,1)


/**
  * @brief  App init program
  * @param  None
  * @retval 0 for success, other for error.
  */
INIT_REG_LEVEL_3(Demo1_init)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* Enable GPIO clocks */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

    /* LED GPIO Configuration ------------------------------------------------*/
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1 ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;/* Only in OUT/AF mode */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;  /* Only in OUT/AF mode */
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL; /* Weak in OUT/AF mode */

    GPIO_Init(GPIOB , &GPIO_InitStructure);

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
        RED_BLING();
    }    
}

/******************* (C) COPYRIGHT 2023 Windy Albert ********** END OF FILE ***/
