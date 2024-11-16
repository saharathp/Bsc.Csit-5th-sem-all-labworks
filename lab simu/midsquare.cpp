#include<stdio.h>
int main()
{
    long int seed=1920;
    int i, n, random;
    printf("\n Output by Sahara Thapa.\n\n");
    printf("How many number you want to generate : ");
    scanf("%d", &n);
    printf("Random Numbers are : ");

    for(i = 0; i < n; i++)
    {
        seed = seed * seed;
        seed = seed / 100;       
        seed = seed % 10000;    
        random = seed;
        printf("%d ", random);
        
    }
    printf("\n");
    return 0;
}
