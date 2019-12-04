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
#include "rotary-encoder.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void
ROTARY_ENCODER_Init(rotaryEncoder_st* self, pin_et pin_a, pin_et pin_b)
{
  self->pin_a = pin_a;
  self->pin_b = pin_b;
  self->count = 0;
  self->lastState = 0U;
  self->state = 0U;
}

void
ROTARY_ENCODER_Update(rotaryEncoder_st* self){
    uint8_t sum;
    
    self->state = GPIO_PinRead(self->pin_a) | (GPIO_PinRead(self->pin_b) << 1);
    sum = (self->lastState << 2) | self->state;
    if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011){
        self->count++;
    }
    if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000){
        self->count--;
    }
    self->lastState = self->state;
}