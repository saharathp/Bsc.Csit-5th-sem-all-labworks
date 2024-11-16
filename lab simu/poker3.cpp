#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculateChiSquare(int observed[], int expected[], int size);
double getCriticalValue(int degreesOfFreedom, double significanceLevel);

int main() {
    int sampleSize;
    printf("Enter the sample size: ");
    scanf("%d", &sampleSize);

    int observed[3]; // ALL_DIFFERENT, ONE_PAIR, THREE_OF_A_KIND
    int expected[3];
    double chiSquare;
    double significanceLevel;
    double criticalValue;

    // Input observed frequencies
    printf("Enter the observed frequency for 'All Different': ");
    scanf("%d", &observed[0]);
    printf("Enter the observed frequency for 'One Pair': ");
    scanf("%d", &observed[1]);
    printf("Enter the observed frequency for 'Three of a Kind': ");
    scanf("%d", &observed[2]);

    // Input significance level
    printf("Enter the significance level (e.g., 0.05): ");
    scanf("%lf", &significanceLevel);

    // Calculate expected frequencies
    expected[0] = sampleSize * 0.72; // Approx. 72% of numbers have all different digits
    expected[1] = sampleSize * 0.27; // Approx. 27% of numbers have one pair
    expected[2] = sampleSize * 0.01; // Approx. 1% of numbers have three of a kind

    // Perform chi-square test
    chiSquare = calculateChiSquare(observed, expected, 3);

    // Calculate critical value
    criticalValue = getCriticalValue(2, significanceLevel); // Degrees of freedom is 2 (number of categories - 1)

    // Output results
    printf("Observed frequencies:\n");
    printf("All Different: %d\n", observed[0]);
    printf("One Pair: %d\n", observed[1]);
    printf("Three of a Kind: %d\n", observed[2]);

    printf("\nExpected frequencies:\n");
    printf("All Different: %d\n", expected[0]);
    printf("One Pair: %d\n", expected[1]);
    printf("Three of a Kind: %d\n", expected[2]);

    printf("\nChi-Square Value: %f\n", chiSquare);
    printf("Critical Value: %f\n", criticalValue);

    // Determine if hypothesis is accepted or rejected
    if (chiSquare > criticalValue) {
        printf("Reject the null hypothesis.\n");
    } else {
        printf("Accept the null hypothesis.\n");
    }

    return 0;
}

double calculateChiSquare(int observed[], int expected[], int size) {
    double chiSquare = 0.0;

    for (int i = 0; i < size; i++) {
        double difference = observed[i] - expected[i];
        chiSquare += (difference * difference) / expected[i];
    }

    return chiSquare;
}

// Function to get critical value (for simplicity, only common significance levels are included)
double getCriticalValue(int degreesOfFreedom, double significanceLevel) {
    if (degreesOfFreedom == 2) {
        if (significanceLevel == 0.10) return 4.605;
        if (significanceLevel == 0.05) return 5.991;
        if (significanceLevel == 0.025) return 7.378;
        if (significanceLevel == 0.01) return 9.210;
        if (significanceLevel == 0.005) return 10.597;
    }
    // Add more cases for different degrees of freedom if needed
    return -1; // Invalid case
}

