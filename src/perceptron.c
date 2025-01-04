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

int load_dataset(const char *filename, double inputs[][NUM_INPUTS], int *targets, size_t num_samples) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return 0;
    }

    char line[256];
    size_t sample_count = 0;

    while (fgets(line, sizeof(line), file) && sample_count < num_samples) {
        double feature1, feature2, feature3;
        int target;

        // Parse each line
        if (sscanf(line, "%lf,%lf,%d", &feature1, &feature2, &target) == 3) {
            inputs[sample_count][0] = feature1;
            inputs[sample_count][1] = feature2;
            targets[sample_count] = target;
            ++sample_count;
        }
    }

    fclose(file);
    return 1;
}

    printf("Testing the Perceptron on the dataset:\n");
    int correct_predictions = 0;
    for (int i = 0; i < NUM_SAMPLES; ++i) {
        int prediction = predict(&perceptron, inputs[i]);
        printf("Sample %d: Prediction = %d, Target = %d\n", i + 1, prediction, targets[i]);
        if (prediction == targets[i]) {
            ++correct_predictions;
        }
    }

    printf("Accuracy: %.2f%%\n", (correct_predictions / (double)NUM_SAMPLES) * 100);

    return 0;
}
