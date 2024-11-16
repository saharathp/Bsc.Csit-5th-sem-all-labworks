#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

int steps = 0;

void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
            steps++;
        }
    }
}

float knapsack(Item items[], int n, int W) {
    sortItemsByRatio(items, n);

    int currentWeight = 0;
    float finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            finalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
        steps++;
    }

    return finalValue;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    float maxValue = knapsack(items, n, W);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    printf("Total number of steps: %d\n", steps);

    return 0;
}
 
