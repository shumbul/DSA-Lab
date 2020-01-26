#include<stdio.h>
#include<math.h>
int main()
{
int n,bit,j=0;
printf("Enter the positive number(<=100000)\n");
scanf("%d",&n);
for(int i=0;i<100000;i++)
{
 if(j<=n)
{
j=pow(2,i);
bit=i;
}
}
printf("bits : %d\n",bit);
return 0;
}

