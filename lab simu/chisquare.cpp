#include <stdio.h>

#define MAX_OBSERVED 20

struct ChiSquare {
    int n;
    int observed[MAX_OBSERVED];
    int N;
    int Expected;
    float Calculation[MAX_OBSERVED];
    float final;
    float critical;
};

void get_data(struct ChiSquare *c) {
    printf("How many numbers?\n");
    scanf("%d", &c->n);
    printf("Enter the observed frequency:\n");
    for (int i = 0; i < c->n; i++) {
        printf("Enter %dth number: ", i + 1);
        scanf("%d", &c->observed[i]);
    }
}

void calculate(struct ChiSquare *c) {
    c->N = 0;
    c->final = 0.00;
    for (int i = 0; i < c->n; i++) {
        c->N += c->observed[i];
    }
    c->Expected = c->N / c->n;
    for (int i = 0; i < c->n; i++) {
        c->Calculation[i] = ((c->observed[i] - c->Expected) * (c->observed[i] - c->Expected)) / (float)c->Expected;
        c->final += c->Calculation[i];
    }
}

void display(struct ChiSquare *c) {
    printf("%5s%5s%5s%22s\n", "S.No", "Oi", "Ei", "((Oi-Ei)*(Oi-Ei))/Ei");
    for (int i = 0; i < c->n; i++) {
        printf("%5d%5d%5d%10.2f\n", i + 1, c->observed[i], c->Expected, c->Calculation[i]);
    }
    printf("-------------------------------------------------------\n");
    printf("%10d%15.2f\n", c->N, c->final);
}

void conclude(struct ChiSquare *c) {
    printf("\nEnter the critical value:\n");
    scanf("%f", &c->critical);
    if (c->final < c->critical) {
        printf("The test is accepted\n");
    } else {
        printf("The test is rejected\n");
    }
}

int main() {
    struct ChiSquare c;
    get_data(&c);
    calculate(&c);
    display(&c);
    conclude(&c);
    return 0;
}

