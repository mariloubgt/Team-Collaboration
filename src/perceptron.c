#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Inputs in this case: Weather, Soil, Resources
#define INPUTS 3 

//Defining the structure 
typedef struct {
    double weights[INPUTS];
    double bias;
} Perceptron;
