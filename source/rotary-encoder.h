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

#ifndef ROTARY_ENCODER_4544fd18_15b9_11ea_ba0b_705a0f25cb51
#define ROTARY_ENCODER_4544fd18_15b9_11ea_ba0b_705a0f25cb51

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * \brief Source file version tag
 *        
 *        version info: [15:8] main [7:0] beta
 */
#define __ROTARY_ENCODER_VERSION      (0x0001u)

/* Includes ------------------------------------------------------------------*/
#include "mcu.h"
/* Exported types ------------------------------------------------------------*/
typedef struct
{
  pin_et pin_a;
  pin_et pin_b;
  volatile uint8_t state;
  volatile uint8_t lastState;
  volatile int32_t count;
  volatile int32_t pulse;
  
}rotaryEncoder_st;
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void
ROTARY_ENCODER_Init(rotaryEncoder_st* self, pin_et pin_a, pin_et pin_b);

void
ROTARY_ENCODER_Update(rotaryEncoder_st* self);

void
ROTARY_ENCODER_SetCount(rotaryEncoder_st* self, int32_t count);
#ifdef __cplusplus
}
#endif

#endif /* ROTARY_ENCODER_4544fd18_15b9_11ea_ba0b_705a0f25cb51 */

