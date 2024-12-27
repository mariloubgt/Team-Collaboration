#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Inputs in this case: Weather, Soil, Resources
#define INPUTS 3 

//Defining the structure 
typedef struct
{
    double weights[INPUTS];
    double bias;
} Perceptron;

//Step activation function
int step_function(double sum)
{
    return (sum >= 0) ? 1 : 0; 
}

//Calculating the weighted sum of inputs "net_input"
double net_input (const Perceptron *perceptron, const double *inputs) 
{
    double sum=0;
    for (int i=0; i <NUM_INPUTS; i++) {
        sum += perceptron-> weights[i] * inputs[i];
    }
    sum += perceptron-> bias;
    return sum;
}    
