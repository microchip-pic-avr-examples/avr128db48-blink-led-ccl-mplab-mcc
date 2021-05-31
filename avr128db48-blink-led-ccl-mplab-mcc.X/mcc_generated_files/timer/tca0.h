/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   2.0.0
*/
/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/


#ifndef TCA0_H_INCLUDED
#define TCA0_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "../system/system.h"
#include "timer_interface.h"
#include "../system/utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialize tca interface
 *
 * \return Initialization status.
 */
    
typedef void (*TCA0_cb_t)(void);    

extern const struct TMR_INTERFACE TCA0_Interface;

void TCA0_Initialize(void);
void TCA0_Start(void);
void TCA0_Stop(void);
void TCA0_OverflowCallbackRegister(TCA0_cb_t cb);
void TCA0_Compare0CallbackRegister(TCA0_cb_t cb);
void TCA0_Compare1CallbackRegister(TCA0_cb_t cb);
void TCA0_Compare2CallbackRegister(TCA0_cb_t cb);
void TCA0_EnableInterrupt(void);
void TCA0_DisableInterrupt(void);
uint16_t TCA0_Read(void);
void TCA0_Write(uint16_t timerVal);
void TCA0_ClearOverflowInterruptFlag(void);
bool TCA0_IsOverflowInterruptEnabled(void);
void TCA0_ClearCMP0InterruptFlag(void);
bool TCA0_IsCMP0InterruptEnabled(void);
void TCA0_ClearCMP1InterruptFlag(void);
bool TCA0_IsCMP1InterruptEnabled(void);
void TCA0_ClearCMP2InterruptFlag(void);
bool TCA0_IsCMP2InterruptEnabled(void);

#ifdef __cplusplus
}
#endif

#endif /* TCA0_H_INCLUDED */