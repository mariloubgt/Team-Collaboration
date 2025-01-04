#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Number of input features: Weather, Soil, Resources
#define NUM_INPUTS 3 
//Number of data samples (optional)
#define NUM_SAMPLES 100 

typedef struct {
    double weights[NUM_INPUTS];
    double bias;
} Perceptron;
 
//Activation function (step function)
int step_function(double net_input) {
    return (net_input >= 0) ? 1 : 0;
}
