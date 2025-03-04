#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int board[20], count = 0, steps = 0;

void print(int n) {
    printf("\n\nSolution %d:\n\n", ++count);
    for (int i = 1; i <= n; ++i)
        printf("\t%d", i);
    for (int i = 1; i <= n; ++i) {
        printf("\n\n%d", i);
        for (int j = 1; j <= n; ++j) {
            if (board[i] == j)
                printf("\tQ");
            else
                printf("\t-");
        }
    }
    printf("\n");
}

int place(int row, int column) {
    for (int i = 1; i <= row - 1; ++i) {
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row, int n) {
    steps++;
    for (int column = 1; column <= n; ++column) {
        if (place(row, column)) {
            board[row] = column;
            if (row == n)
                print(n);
            else
                queen(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("N Queens Problem Using Backtracking -\n\nEnter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    printf("\nTotal number of steps: %d\n", steps);
    return 0;
}

