#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_INPUTS 3   // Number of input features (Weather, Soil, Resources)
#define NUM_SAMPLES 100 // Number of data samples

typedef struct {
    double weights[NUM_INPUTS];
    double bias;
} Perceptron;
 
