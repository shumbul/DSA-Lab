#include<stdio.h>
int main()
{
int n;
printf("enter the number of elements in the array:\n");
scanf("%d",&n);
int a[n],l[n];
printf("enter the elements\n");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
l[i]=1;
}
for(int j=1;j<n;j++)
{
for(int k=0;k<j;k++)
{
if((a[k]<a[j]) && (l[j]<l[k]+1))
{
l[j]=l[k]+1;
}
}
}
int max=l[0];
for(int m=0;m<n;m++)
{
if(l[m]>max)
max=l[m];
}
printf("the length of longest increasing subsequence=%d\n",max);
return 0;
}
