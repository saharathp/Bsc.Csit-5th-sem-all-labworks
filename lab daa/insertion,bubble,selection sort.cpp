#include<stdio.h>

int count1 = 0;
int count2 = 0;
int count3 = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int A[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            count1++;
            if(A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void selection(int A[], int n) {
    int i, j, minindex, minvalue;
    for(i = 0; i < n - 1; i++) {
        minindex = i;
        minvalue = A[i];
        for(j = i + 1; j < n; j++) {
            count2++;
            if(A[j] < A[minindex]) {
                minindex = j;
                minvalue = A[j];
            }
        }
        swap(&A[i], &A[minindex]);
    }
}

void insertion(int A[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = A[i];
        j=i-1;
        
        while(j>=0 && A[j]>key)
        {
            count3=count3+1;
            A[j + 1] = A[j];
            j=j-1;
        }
        
        /*for(j = i - 1; j >= 0 && A[j] > key; j--) {
        	printf("LOOP");
            count3++;
            A[j + 1] = A[j];
        }*/
        A[j + 1] = key;
    }
}

int main() {
	printf("\nOutput by Sahara Thapa.\n\n");
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    insertion(A, n);
    bubble(A, n);
    selection(A, n);
    

    printf("\n The complexity of bubble is: %d", count1);
    printf("\n The complexity of selection is: %d", count2);
    printf("\n The complexity of insertion is: %d", count3);
 
    return 0;
}
