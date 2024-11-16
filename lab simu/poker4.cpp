#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double calculateChiSquare(int observed[], double expected[], int size);
void chiSquareTest(double chiSquare, int degreesOfFreedom);

int main() {
    int sampleSize;
    printf("Enter the sample size: ");
    scanf("%d", &sampleSize);

    int observed[5]; // ALL_DIFFERENT, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND, ALL_SAME
    double expected[5];
    double chiSquare;

    // Input observed frequencies
    printf("Enter the observed frequency for 'All Different': ");
    scanf("%d", &observed[0]);
    printf("Enter the observed frequency for 'One Pair': ");
    scanf("%d", &observed[1]);
    printf("Enter the observed frequency for 'Two Pair': ");
    scanf("%d", &observed[2]);
    printf("Enter the observed frequency for 'Three of a Kind': ");
    scanf("%d", &observed[3]);
    printf("Enter the observed frequency for 'All Same': ");
    scanf("%d", &observed[4]);

    // Probabilities for each category (out of 10 digits)
    double probAllDifferent = 0.504;    // Approx. 50.4% of numbers have all different digits
    double probOnePair = 0.432;         // Approx. 43.2% of numbers have one pair
    double probTwoPair = 0.027;         // Approx. 2.7% of numbers have two pairs
    double probThreeOfAKind = 0.036;    // Approx. 3.6% of numbers have three of a kind
    double probAllSame = 0.001;         // Approx. 0.1% of numbers have all same digits

    // Calculate expected frequencies (scaled by sample size)
    expected[0] = probAllDifferent * sampleSize;
    expected[1] = probOnePair * sampleSize;
    expected[2] = probTwoPair * sampleSize;
    expected[3] = probThreeOfAKind * sampleSize;
    expected[4] = probAllSame * sampleSize;

    // Perform chi-square test
    chiSquare = calculateChiSquare(observed, expected, 5);

    // Output results
    printf("\nObserved frequencies:\n");
    printf("All Different: %d\n", observed[0]);
    printf("One Pair: %d\n", observed[1]);
    printf("Two Pair: %d\n", observed[2]);
    printf("Three of a Kind: %d\n", observed[3]);
    printf("All Same: %d\n", observed[4]);

    printf("\nExpected frequencies (scaled by sample size):\n");
    printf("All Different: %.2f\n", expected[0]);
    printf("One Pair: %.2f\n", expected[1]);
    printf("Two Pair: %.2f\n", expected[2]);
    printf("Three of a Kind: %.2f\n", expected[3]);
    printf("All Same: %.2f\n", expected[4]);

    printf("\nChi-Square Value: %.2f\n", chiSquare);

    // Perform chi-square test of hypothesis
    chiSquareTest(chiSquare, 4); // Degrees of freedom = 5 categories - 1

    return 0;
}

double calculateChiSquare(int observed[], double expected[], int size) {
    double chiSquare = 0.0;

    for (int i = 0; i < size; i++) {
        double difference = observed[i] - expected[i];
        chiSquare += (difference * difference) / expected[i];
    }

    return chiSquare;
}

void chiSquareTest(double chiSquare, int degreesOfFreedom) {
    // Critical value for chi-square test with 95% confidence level and df = degreesOfFreedom
    double criticalValue = 9.488;

    printf("\nChi-Square Test of Hypothesis:\n");
    printf("Degrees of Freedom: %d\n", degreesOfFreedom);
    printf("Critical Value (alpha = 0.05): %.3f\n", criticalValue);
    printf("Chi-Square Value: %.3f\n", chiSquare);

    if (chiSquare <= criticalValue) {
        printf("\nNull hypothesis is accepted.\n");
    } else {
        printf("\nNull hypothesis is rejected.\n");
    }
}

