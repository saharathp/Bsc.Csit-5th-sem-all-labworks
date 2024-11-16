#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5

// Function to calculate minimum number of scalar multiplications and create m and s tables
void matrix_chain_order(int p[], int n, int m[][MAX_SIZE], int s[][MAX_SIZE]) {
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print matrix
void print_matrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int arr[n + 1]; // Array to store dimensions of matrices

    printf("Enter the dimensions of the matrices (e.g., for A1 with dimensions m1xm2, enter m1, m2, ..., mn):\n ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize m and s tables
    int m[MAX_SIZE][MAX_SIZE];
    int s[MAX_SIZE][MAX_SIZE];
    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j < MAX_SIZE; j++) {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    // Compute minimum multiplications and fill m and s tables
    matrix_chain_order(arr, n + 1, m, s);

    // Print minimum multiplications table (m)
    printf("\nMinimum Multiplications (m) Table:\n");
    print_matrix(m, MAX_SIZE, MAX_SIZE);

    // Print splitting point table (s)
    printf("\nSplitting Point (s) Table:\n");
    print_matrix(s, MAX_SIZE, MAX_SIZE);

    printf("\nMinimum number of scalar multiplications: %d\n", m[1][n]);

    return 0;
}

