#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 10
int determinant(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
int multiplicativeInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}
void getCofactor(int matrix[MAX_SIZE][MAX_SIZE], int temp[MAX_SIZE][MAX_SIZE], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
int calculateDeterminant(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int det = 0;
    if (n == 1) {
        return matrix[0][0];
    }

    int temp[MAX_SIZE][MAX_SIZE];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        det += sign * matrix[0][f] * calculateDeterminant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

void transpose(int matrix[MAX_SIZE][MAX_SIZE], int transpose[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void adjoint(int matrix[MAX_SIZE][MAX_SIZE], int adjoint[MAX_SIZE][MAX_SIZE], int n) {
    if (n == 1) {
        adjoint[0][0] = 1;
        return;
    }

    int temp[MAX_SIZE][MAX_SIZE];
    int sign = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getCofactor(matrix, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adjoint[j][i] = sign * calculateDeterminant(temp, n - 1);
        }
    }
}

void matrixMultiply(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void hillCipherEncrypt(char plaintext[], int keyMatrix[MAX_SIZE][MAX_SIZE], int keySize) {
    int plaintextLength = strlen(plaintext);
    int blockLength = keySize;
    if (plaintextLength % blockLength != 0) {
        int padding = blockLength - (plaintextLength % blockLength);
        plaintextLength += padding;
        for (int i = 0; i < padding; i++) {
            plaintext[plaintextLength - 1 - i] = 'X';   
        }
    }

    int numBlocks = plaintextLength / blockLength;
    int plaintextBlocks[MAX_SIZE][MAX_SIZE];
    int cipherBlocks[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < blockLength; j++) {
            plaintextBlocks[i][j] = toupper(plaintext[i * blockLength + j]) - 'A';
        }
    }
  
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < blockLength; j++) {
            cipherBlocks[i][j] = 0;
            for (int k = 0; k < blockLength; k++) {
                cipherBlocks[i][j] += keyMatrix[j][k] * plaintextBlocks[i][k];
            }
            cipherBlocks[i][j] %= 26;   
        }
    }
	 
    printf("Encrypted Ciphertext: ");
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < blockLength; j++) {
            printf("%c", cipherBlocks[i][j] + 'A');
        }
    }
    printf("\n");
}

int main() {
	printf("\n\n******** HILL CIPHER **********\n\n");
    char plaintext[100];
    int keyMatrix[MAX_SIZE][MAX_SIZE];
    int keySize;
 
    printf("Enter the plaintext to encrypt (in uppercase): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  
 
    printf("Enter the size of the key matrix (n x n): ");
    scanf("%d", &keySize);
 
    printf("Enter the key matrix elements (separated by spaces):\n");
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf("%d", &keyMatrix[i][j]);
        }
    }
 
    hillCipherEncrypt(plaintext, keyMatrix, keySize);

    return 0;
}

