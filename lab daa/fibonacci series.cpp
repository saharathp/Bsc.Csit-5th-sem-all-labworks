//LAB 3:Write a program to demonstrate the concept analysis of Fibonacci Series Algorithm
#include<stdio.h>
#include<Stdio.h>
int main()
{
	printf("\nOutput by Sahara Thapa.\n\n");
	int i,n;
	int f1=0,f2=1,f3;
	printf("Enter the number of terms:");
	scanf("%d",&n);
	printf("\n%d\n%d",f1,f2);
	for(i=2;i<=n;i++)
	{
		
		f3=f1+f2;
		printf("\n%d",f3);
		f1=f2;
		f2=f3;
	}

	return f3;

}
