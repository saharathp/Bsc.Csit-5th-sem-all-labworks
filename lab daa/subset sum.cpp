#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int steps = 0;

bool subsetSum(int set[], int n, int sum, bool subset[MAX][MAX]) {
    steps++;

    // If sum is 0, then answer is true
    if (sum == 0)
        return true;

    // If there are no elements and sum is not 0, then answer is false
    if (n == 0)
        return false;

    // If last element is greater than sum, then ignore it
    if (set[n - 1] > sum)
        return subsetSum(set, n - 1, sum, subset);

    // Store result in subset table and return true if
    // set[n-1] is included in the subset or not
    if (subset[n][sum] == false) {
        subset[n][sum] = subsetSum(set, n - 1, sum, subset) || subsetSum(set, n - 1, sum - set[n - 1], subset);
    }

    return subset[n][sum];
}

void findSubset(int set[], int n, int sum) {
    bool subset[MAX][MAX] = {false};

    if (subsetSum(set, n, sum, subset))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");

    printf("Total number of steps: %d\n", steps);
}

int main() {
    int set[MAX], n, sum;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the sum to find: ");
    scanf("%d", &sum);

    findSubset(set, n, sum);

    return 0;
}

