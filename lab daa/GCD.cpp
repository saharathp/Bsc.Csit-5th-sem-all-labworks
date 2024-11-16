// LAB 1: Write a program to demonstrate the concept analysis of GCD Algorithm
#include<stdio.h>
#include<conio.h>
int GCD(int,int);
int count=0;
int main()
{
	int a,b;
	printf("\nOutput by Sahara Thapa.\n\n");
	printf("Enter the value of a and b:");
	scanf("%d %d",&a,&b);
	int temp;
	if(b>a)
	{
		temp=a;
		a=b;
		b=temp;
	}
	printf("\nGCD is: %d",GCD(a,b));
	printf("\nTotal steps:%d",count);
	return 0;
}
int GCD(int a,int b)
{
	int rem;
	while(b!=0)
	{
		count++;
		rem=a%b;
		a=b;
		b=rem;
	}
	return a;
}
