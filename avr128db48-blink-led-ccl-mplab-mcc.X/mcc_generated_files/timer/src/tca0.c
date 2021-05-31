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


#include "../tca0.h"

const struct TMR_INTERFACE TCA0_Interface = {
    .Initialize = TCA0_Initialize,
    .Start = NULL,
    .Stop = NULL,
    .PeriodCountSet = TCA0_Write,
    .TimeoutCallbackRegister = TCA0_OverflowCallbackRegister,
    .Tasks = NULL
};

void TCA0_DefaultCompare0CallbackRegister(void);
void (*TCA0_CMP0_isr_cb)(void) = &TCA0_DefaultCompare0CallbackRegister;
void TCA0_DefaultCompare1CallbackRegister(void);
void (*TCA0_CMP1_isr_cb)(void) = &TCA0_DefaultCompare1CallbackRegister;
void TCA0_DefaultCompare2CallbackRegister(void);
void (*TCA0_CMP2_isr_cb)(void) = &TCA0_DefaultCompare2CallbackRegister;
void TCA0_DefaultOverflowCallbackRegister(void);
void (*TCA0_OVF_isr_cb)(void) = &TCA0_DefaultOverflowCallbackRegister;

void TCA0_DefaultCompare0CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultCompare1CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultCompare2CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultOverflowCallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_OverflowCallbackRegister(TCA0_cb_t cb)
{
    TCA0_OVF_isr_cb = cb;
}

void TCA0_Compare0CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP0_isr_cb = cb;
}

void TCA0_Compare1CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP1_isr_cb = cb;
}

void TCA0_Compare2CallbackRegister(TCA0_cb_t cb)
{
    TCA0_CMP2_isr_cb = cb;
}

ISR(TCA0_CMP0_vect)
{
    if (TCA0_CMP0_isr_cb != NULL)
        (*TCA0_CMP0_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP0_bm;
}

ISR(TCA0_CMP1_vect)
{
    if (TCA0_CMP1_isr_cb != NULL)
        (*TCA0_CMP1_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP1_bm;
}

ISR(TCA0_CMP2_vect)
{
    if (TCA0_CMP2_isr_cb != NULL)
        (*TCA0_CMP2_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_CMP2_bm;
}

ISR(TCA0_OVF_vect)
{
    if (TCA0_OVF_isr_cb != NULL)
        (*TCA0_OVF_isr_cb)();
    
    TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}


/**
 * \brief Initialize TCA interface
 */
void TCA0_Initialize(void) {
    // Compare 0
    TCA0.SINGLE.CMP0 = 0x1;
        
    // Compare 1
    TCA0.SINGLE.CMP1 = 0x1;
    
    // Compare 2
    TCA0.SINGLE.CMP2 = 0x1;
        
    // Count
    TCA0.SINGLE.CNT = 0x0;
    
    // ALUPD disabled; CMP0EN disabled; CMP1EN disabled; CMP2EN disabled; WGMODE NORMAL; 
    TCA0.SINGLE.CTRLB = 0x0;
    
    // CMP0OV disabled; CMP1OV disabled; CMP2OV disabled; 
    TCA0.SINGLE.CTRLC = 0x0;
    
    // SPLITM disabled; 
    TCA0.SINGLE.CTRLD = 0x0;
    
    // CMD NONE; DIR disabled; LUPD disabled; 
    TCA0.SINGLE.CTRLECLR = 0x0;
    
    // CMD NONE; DIR UP; LUPD disabled; 
    TCA0.SINGLE.CTRLESET = 0x0;
    
    // CMP0BV disabled; CMP1BV disabled; CMP2BV disabled; PERBV disabled; 
    TCA0.SINGLE.CTRLFCLR = 0x0;
    
    // CMP0BV disabled; CMP1BV disabled; CMP2BV disabled; PERBV disabled; 
    TCA0.SINGLE.CTRLFSET = 0x0;
    
    // DBGRUN disabled; 
    TCA0.SINGLE.DBGCTRL = 0x0;
    
    // CNTAEI disabled; CNTBEI disabled; EVACTA CNT_POSEDGE; EVACTB NONE; 
    TCA0.SINGLE.EVCTRL = 0x0;
    
    // CMP0 disabled; CMP1 disabled; CMP2 disabled; OVF disabled; 
    TCA0.SINGLE.INTCTRL = 0x0;
    
    // CMP0 disabled; CMP1 disabled; CMP2 disabled; OVF disabled; 
    TCA0.SINGLE.INTFLAGS = 0x0;
    
    // Period
    TCA0.SINGLE.PER = 0xF423;
    
    // Temporary data for 16-bit Access
    TCA0.SINGLE.TEMP = 0x0;
    
    // CLKSEL DIV16; ENABLE enabled; RUNSTDBY disabled; 
    TCA0.SINGLE.CTRLA = 0x9;
    
}

void TCA0_Start(void)
{
    TCA0.SINGLE.CTRLA|= TCA_SINGLE_ENABLE_bm;
}

void TCA0_Stop(void)
{
    TCA0.SINGLE.CTRLA&= ~TCA_SINGLE_ENABLE_bm;
}

void TCA0_Write(uint16_t timerVal)
{
    TCA0.SINGLE.CNT=timerVal;
}

uint16_t TCA0_Read(void)
{
    uint16_t readVal;

    readVal = TCA0.SINGLE.CNT;

    return readVal;
}

void TCA0_EnableInterrupt(void)
{
        TCA0.SINGLE.INTCTRL = 1 << TCA_SINGLE_CMP0_bp /* Compare 0 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_CMP1_bp /* Compare 1 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_CMP2_bp /* Compare 2 Interrupt: enabled */
	 				| 1 << TCA_SINGLE_OVF_bp; /* Overflow Interrupt: enabled */
}
void TCA0_DisableInterrupt(void)
{
    TCA0.SINGLE.INTCTRL = 0 << TCA_SINGLE_CMP0_bp /* Compare 0 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_CMP1_bp /* Compare 1 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_CMP2_bp /* Compare 2 Interrupt: disabled */
	 				| 0 << TCA_SINGLE_OVF_bp; /* Overflow Interrupt: disabled */
}
void TCA0_ClearOverflowInterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS &= ~TCA_SINGLE_OVF_bm; /* Overflow Interrupt: disabled */
}
bool TCA0_IsOverflowInterruptEnabled(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_OVF_bm) > 0);
}

void TCA0_ClearCMP0InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS &= ~TCA_SINGLE_CMP0_bm; /* Compare Channel-0 Interrupt: disabled */
}

bool TCA0_IsCMP0InterruptEnabled(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP0_bm) > 0);
}

void TCA0_ClearCMP1InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS &= ~TCA_SINGLE_CMP1_bm; /* Compare Channel-1 Interrupt: disabled */
}

bool TCA0_IsCMP1InterruptEnabled(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP1_bm) > 0);
}

void TCA0_ClearCMP2InterruptFlag(void)
{
    TCA0.SINGLE.INTFLAGS &= ~TCA_SINGLE_CMP2_bm; /* Compare Channel-2 Interrupt: disabled */
}

bool TCA0_IsCMP2InterruptEnabled(void)
{
    return ((TCA0.SINGLE.INTFLAGS & TCA_SINGLE_CMP2_bm) > 0);
}