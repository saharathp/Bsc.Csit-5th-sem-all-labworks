#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a Job
typedef struct Job {
   int deadline;    // Deadline of Job
   int profit;      // Profit if Job is completed before or on deadline
} Job;

// Function to compare Jobs based on profit (descending order)
int compare(const void* a, const void* b) {
   Job* job1 = (Job*)a;
   Job* job2 = (Job*)b;
   return (job2->profit - job1->profit);
}

// Function to find the minimum of two numbers
int min(int num1, int num2) {
   return (num1 < num2) ? num1 : num2;
}

int main() {
   int n;
   printf("Enter the number of jobs: ");
   scanf("%d", &n);

   Job jobs[n]; // Array to store Jobs

   // Input Jobs details
   printf("Enter job details (deadline and profit):\n");
   for (int i = 0; i < n; i++) {
      scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
   }

   // Sort Jobs based on profit (decreasing order)
   qsort(jobs, n, sizeof(Job), compare);

   printf("Maximum profit sequence of Jobs: \n");

   bool slot[n];  // To keep track of free time slots

   // Initialize all slots to be free
   for (int i = 0; i < n; i++)
      slot[i] = false;

   int totalProfit = 0;

   // Iterate through all given Jobs
   for (int i = 0; i < n; i++) {
      // Find a free slot for this Job starting from its deadline
      for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
         // Free slot found
         if (slot[j] == false) {
            slot[j] = true;
            totalProfit += jobs[i].profit;
            break;
         }
      }
   }

   // Print the sequence of selected Jobs
   for (int i = 0; i < n; i++) {
      if (slot[i]) {
         printf("%d ", i + 1); // Print 1-based index of job
      }
   }
   printf("\n");

   printf("Total profit: %d\n", totalProfit);

   return 0;
}

