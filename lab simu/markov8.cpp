#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void matrix_multiply(double *result, double *matrix, double *vector, int size);
void print_vector(double *vector, int size);

int main() {
	printf("Output By Sahara Thapa.\n");
    int num_states;
    printf("Enter the number of states in the Markov chain: ");
    scanf("%d", &num_states);

    // Allocate memory for transition matrix and initial state vector
    double *transition_matrix = (double *)malloc(num_states * num_states * sizeof(double));
    double *initial_state = (double *)malloc(num_states * sizeof(double));

    // Read transition matrix from user input
    printf("\nEnter the transition matrix (%d x %d):\n", num_states, num_states);
    for (int i = 0; i < num_states; i++) {
        for (int j = 0; j < num_states; j++) {
            printf("Probability of transition from State %d to State %d: ", i, j);
            scanf("%lf", &transition_matrix[i * num_states + j]);
        }
    }

    // Read initial state vector from user input
    printf("\nEnter the initial state vector (%d x 1):\n", num_states);
    for (int i = 0; i < num_states; i++) {
        printf("Probability of starting in State %d: ", i);
        scanf("%lf", &initial_state[i]);
    }

    // Number of steps to simulate
    int num_steps;
    printf("\nEnter the number of steps to simulate: ");
    scanf("%d", &num_steps);

    printf("\nSimulation of Markov Chain:\n");
    printf("Initial state vector:\n");
    print_vector(initial_state, num_states);

    // Perform matrix-vector multiplication for each step
    double *current_state = (double *)malloc(num_states * sizeof(double));
    for (int step = 1; step <= num_steps; step++) {
        matrix_multiply(current_state, transition_matrix, initial_state, num_states);
        printf("\nStep %d: State vector:\n", step);
        print_vector(current_state, num_states);
        // Update initial state for next step
        for (int i = 0; i < num_states; i++) {
            initial_state[i] = current_state[i];
        }
    }

    // Free allocated memory
    free(transition_matrix);
    free(initial_state);
    free(current_state);

    return 0;
}

// Function to perform matrix-vector multiplication
void matrix_multiply(double *result, double *matrix, double *vector, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0.0;
        for (int j = 0; j < size; j++) {
            result[i] += matrix[i * size + j] * vector[j];
        }
    }
}

// Function to print a vector
void print_vector(double *vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.3f ", vector[i]);
    }
    printf("\n");
}

