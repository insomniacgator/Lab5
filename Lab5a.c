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
#include <driverlib/uartstdio.h>

#include "sample_signals.h"
#include "dsp_defines.h"

// CMSIS Math includes
#include "arm_math.h"
#include "arm_const_structs.h"


/*************************************Defines***************************************/
#define BUCKET_NUM      100

/********************************Public Variables***********************************/
uint32_t fftSize = FFT_SAMPLES;
uint32_t ifftFlag = 0;
arm_rfft_fast_instance_f32 S;
uint32_t maxIndex = 0;
arm_status status;
float32_t maxValue;
int i;

// Bucket array
int bucketCounts[BUCKET_NUM] = {0};
float bucketLimits[BUCKET_NUM];

// all variables
static float32_t complexFFT[FFT_SAMPLES], realFFT[FFT_SAMPLES_HALF],
        imagFFT[FFT_SAMPLES_HALF], angleFFT[FFT_SAMPLES_HALF],
        powerFFT[FFT_SAMPLES_HALF], magnitudeFFT[FFT_SAMPLES_HALF];

/************************************MAIN*******************************************/
void main() {
    status = ARM_MATH_SUCCESS;
    UART_Init();

    // create an instance of a 1024-point FFT (results are of float32)
    arm_rfft_fast_init_f32(&S, fftSize);

    // perform FFT on the sample signal (sample_signals.h)
    arm_rfft_fast_f32(&S, Hz_25_5_Imposed, complexFFT, ifftFlag);


    for (i=0; i<(fftSize/2); i++)
    {
        // Compute magnitudes of each frequency component
        realFFT[i] = complexFFT[2 * i];
        imagFFT[i] = complexFFT[2 * i + 1];
        arm_status result = arm_sqrt_f32(realFFT[i] * realFFT[i] + imagFFT[i] * imagFFT[i], &magnitudeFFT[i]);
        // Compute the power of each frequency component by squaring the magnitude
        powerFFT[i] = magnitudeFFT[i] * magnitudeFFT[i];
        // Get maximum value & index of maximum value within the power vector
        if (powerFFT[i] > maxValue)
        {
            // Remember to offset index to account for DC value
            // SHOULD I DO i-1 FOR BOTH OF THESE?
            maxValue = powerFFT[i];
            maxIndex = i;
        }
    }


    // Compute bucket limits depending on maximum value and resolution
        // Resolution determines how fine (close together) bucket limits are.
    float resolution = maxValue / BUCKET_NUM;
    for (i=0; i<BUCKET_NUM; i++)
    {
        bucketLimits[i] = i * resolution;
    }

    // Increment the counts of each bucket depending on bucket limits and the resulting magnitudes
    for (i=0; i<(fftSize/2); i++)
    {
        for (int j=0; j<BUCKET_NUM-1; j++)
        {
            if (powerFFT[i] >= bucketLimits[j] && powerFFT[i] < bucketLimits[j+1])
            {
                bucketCounts[j]++;
                break;
            }
        }
    }

    // Calculate the dominant frequency
    float dominantFrequency = (float)maxIndex * SAMPLING_FREQUENCY / (float)fftSize;
    // Output dominant frequency
    //char d_freq
    UARTprintf("Dominant Frequency: %f\n", dominantFrequency);

    while (1);
}


/************************************MAIN*******************************************/


