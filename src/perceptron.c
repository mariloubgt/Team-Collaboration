#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_INPUTS 2   // Number of input features (Weather, Resources)
#define NUM_SAMPLES 100 // Number of data samples

typedef struct {
    double weights[NUM_INPUTS];
    double bias;
} Perceptron;


double net_input(const Perceptron *perceptron, const double *inputs) {
    double sum = 0.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        sum += perceptron->weights[i] * inputs[i];
    }
    sum += perceptron->bias;
    return sum;
}