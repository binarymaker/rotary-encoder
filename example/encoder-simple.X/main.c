/**\cond
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  \endcond*/

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
#include "rotary-encoder.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
rotaryEncoder_st encoder;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

int
main(void)
{ 
  int32_t encoder_lastCount = 0;
  MCU_Init();
  ROTARY_ENCODER_Init(&encoder, P_C0, P_C1);
  
  MCU_INTERRUPT_ENABLE();
  
  USART_Printf("Rotary Encoder Example\n\r", 0);
  while(1)
  {
    if (encoder_lastCount != encoder.count)
    {
      USART_Printf("Encoder count %d \n\r", encoder.count);
      encoder_lastCount = encoder.count;
    }
  }
}
