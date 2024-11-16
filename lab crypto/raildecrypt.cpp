#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
 int i,j,k,len,rails,count,code[100][1000];
    char str[1000];
    printf("\nOutput By Sahara Thapa.\n\n");
    printf("Enter a cipher text: \n");
    gets(str);

    len=strlen(str);
    
 printf("Enter number of rails:\n");
 scanf("%d",&rails);
 for(i=0;i<rails;i++)
 {
  for(j=0;j<len;j++)
  {
   code[i][j]=0;
  }
 }
count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
   
  code[i][j]=-1; 
  j++;
 }
 
}
else
{

 for(i=rails-2;i>0;i--)
 {
  code[i][j]=-1;
 j++;
 }  
} 

count++;
}

k=0;
for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
  if(code[i][j]!=0)
  {
     code[i][j]=(int)str[k];
     k++;
  }
 } 
}
 
count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
   
  printf("%c",code[i][j]); 
  j++;
 }
 
}
else
{

 for(i=rails-2;i>0;i--)
 {
  printf("%c",code[i][j]);
 j++;
 }  
} 

count++;
}
printf("\n");
}

