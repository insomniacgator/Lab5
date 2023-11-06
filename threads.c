// G8RTOS_Threads.c
// Date Created: 2023-07-25
// Date Updated: 2023-07-27
// Defines for thread functions.

/************************************Includes***************************************/

#include "./threads.h"

#include "./MultimodDrivers/multimod.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <driverlib/timer.h>

#include "dsp_defines.h"

// CMSIS Math includes
#include "arm_math.h"
#include "arm_const_structs.h"

/*************************************Defines***************************************/

#define BUCKET_NUM      100

// remember nyquist theorem
#define SAMPLE_FREQ     2000

/*********************************Global Variables**********************************/

// signal array
static float signal_samples[FFT_SAMPLES];

uint32_t sample_index = 0;

// Can't fit this all in one thread (unless you have a very large stack size)
static float32_t complexFFT[FFT_SAMPLES], realFFT[FFT_SAMPLES_HALF],
        imagFFT[FFT_SAMPLES_HALF], angleFFT[FFT_SAMPLES_HALF],
        powerFFT[FFT_SAMPLES_HALF], magnitudeFFT[FFT_SAMPLES_HALF];


/*************************************Threads***************************************/

void Idle_Thread(void) {
    while(1);
}

/********************************Periodic Threads***********************************/



/*******************************Aperiodic Threads***********************************/

