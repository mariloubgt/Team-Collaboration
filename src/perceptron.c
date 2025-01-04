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

// Train the Perceptron
void train_perceptron(Perceptron *perceptron,
                      const double inputs[][NUM_INPUTS],
                      const int *targets,
                      size_t num_samples,
                      double learning_rate,
                      int max_epochs) {
    for (int epoch = 0; epoch < max_epochs; ++epoch) {
        for (size_t i = 0; i < num_samples; ++i) {
            int prediction = predict(perceptron, inputs[i]);
            double error = targets[i] - prediction;

            // Update weights and bias
            for (int j = 0; j < NUM_INPUTS; ++j) {
                perceptron->weights[j] += learning_rate * error * inputs[i][j];
            }
            perceptron->bias += learning_rate * error;
        }
    }}