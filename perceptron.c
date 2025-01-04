#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_INPUTS 2
#define NUM_SAMPLES 100 

typedef struct {
    double weights[NUM_INPUTS];
    double bias;
} Perceptron;

int step_function(double net_input){
    return (net_input >= 0)? 1:0;
}
