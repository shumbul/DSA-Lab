#include<stdio.h>
int main()
{
int a[100], i, j, k=0, n;
printf("enter the whole number:\n");
scanf("%d", &n);
a[0]=n;
for(i=1;i<100;i++)
{
a[i]=(a[i-1]*n)+k;    //multiplying the unit digit and adding the carry
k=a[i]/10;            //initialising the new carry
a[i]=a[i]%10;         //taking only the last digit of a[i] leaving the carry
if((k==0)&&(a[i]==1)) //remainder or carry should be 0 and last digit should be 1
break;
}
printf("the required number is :\n");
for (j=i; j>=0;j--)   //printing the array reversed
printf("%d", a[j]);
}
