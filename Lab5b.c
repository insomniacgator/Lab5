// Lab 5, uP2 Fall 2023
// Created: 2023-07-31
// Updated: 2023-08-01
// Lab 5 is intended to introduce you to DSP using real-time systems.
// For part a you will be conducting FFT on a test signal once to
// extract its dominant frequency.

/************************************Includes***************************************/
#include "G8RTOS/G8RTOS.h"
#include "./MultimodDrivers/multimod.h"
#include "threads.h"

#include "sample_signals.h"
#include "dsp_defines.h"

// CMSIS Math includes
#include "arm_math.h"
#include "arm_const_structs.h"


/************************************MAIN*******************************************/
void main() {

    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    G8RTOS_Init();
    multimod_init();

    // your code 

    G8RTOS_Launch();
    while (1);
}

/************************************MAIN*******************************************/
