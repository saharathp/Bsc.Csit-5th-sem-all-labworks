#include <stdio.h>

// Function to generate pseudo-random numbers using Mixed Congruential Method
void mixedCongruentialMethod(int n, int seed1, int seed2) {
    // Constants for the linear congruential generators
    const int a1 = 134775813;
    const int a2 = 1103515245;
    const int c = 1;
    const int m = 2147483648; // 2^31
    
    // Initial values for the generators
    int x1 = seed1;
    int x2 = seed2;
    
    printf("Pseudo-random numbers generated using Mixed Congruential Method:\n");
    for (int i = 0; i < n; ++i) {
        x1 = (a1 * x1 + c) % m;
        x2 = (a2 * x2 + c) % m;
        
        // Combine results from both generators
        int random_number = (x1 - x2) % m;
        if (random_number < 0)
            random_number += m;
        
        printf("%d\n", random_number);
    }
}

int main() {
	printf("\nOutput By Prashant Oli.\n\n");
    int n; // Number of random numbers to generate
    int seed1, seed2; // Seeds for the two generators
    
    // Input parameters from user
    printf("Enter number of random numbers to generate: ");
    scanf("%d", &n);
    
    printf("Enter seed for first generator (x1): ");
    scanf("%d", &seed1);
    
    printf("Enter seed for second generator (x2): ");
    scanf("%d", &seed2);
    
    // Generate random numbers using Mixed Congruential Method
    mixedCongruentialMethod(n, seed1, seed2);
    
    return 0;
}

