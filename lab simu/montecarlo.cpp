#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	printf("\nOutput by Sahara Thapa.\n\n");
    int i, n;
    double x, y, pi,d;
    int count = 0;

    printf("Enter the number of iterations: ");
    scanf("%d", &n);

    // Monte Carlo simulation
    for (i = 0; i < n; i++) {
        // Generate random points in the unit square
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        d = x*x+y*y;
        // Check if the point is within the unit circle
        if (d <= 1) {
            count++;
        }
    }

    // Estimate p
    pi = 4 * (double)count / n;

    // Print the result
    printf("Estimated value of pi: %lf\n", pi);

    return 0;
}

