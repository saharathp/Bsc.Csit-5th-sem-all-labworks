#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double autocorrelation(double *data, int n, int m, int i_start) {
  double sum = 0.0;
  for (int k = i_start; k <= n - m - 1; k++) {
    sum += (data[k] * data[k + m]);
  }
  sum /= (n - m - i_start); // Adjusted for correct denominator
  sum -= 0.25; // Subtract 0.25 from pim
  return sum;
}

int test_independence(double *data, int n, int m, int i_start) {
  double pim = autocorrelation(data, n, m, i_start);
  double gim = sqrt((13 * n + 7) / (12.0 * (n + 1))); // Standard deviation (use 12.0 for accurate division)
  double zo = pim / gim; // Test statistic

  double z_alpha = 1.96; // Critical value (95% confidence level)

  if (-z_alpha <= zo && zo <= z_alpha) {
    return 0; // Do not reject the null hypothesis of independence
  } else {
    return 1; // Reject the null hypothesis of independence
  }
}

int main() {
  int N; // Number of data points
  printf("Enter the number of data points (N): ");
  scanf("%d", &N);

  int m; // Gap length (m)
  printf("Enter the gap length (m): ");
  scanf("%d", &m);

  int i_start; // Starting index
  printf("Enter the starting index (i_start): ");
  scanf("%d", &i_start);

  // Generate N random numbers
  srand(time(NULL));
  double random_numbers[N];
  for (int i = 0; i < N; i++) {
    random_numbers[i] = (double)rand() / RAND_MAX;
  }

  int reject_null = test_independence(random_numbers, N, m, i_start);

  double pim = autocorrelation(random_numbers, N, m, i_start);
  double gim = sqrt((13 * N + 7) / (12.0 * (N + 1))); // Standard deviation (use 12.0 for accurate division)
  double zo = pim / gim; // Test statistic

  printf("Zo = %.4f\n", zo);
  printf("Z_alpha = %.4f\n", 1.96);

  if (reject_null == 0) {
    printf("Do not reject the null hypothesis of independence.\n");
  } else {
    printf("Reject the null hypothesis of independence.\n");
  }

  return 0;
}
