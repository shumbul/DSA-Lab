#include<stdio.h>
#include<math.h>
float sqt(int n)
{
int start=0,end;
float mid;
float ans;
end=n;
while(start<=end)
{
mid=(start+end)/2;
if((mid*mid)==n)
{
ans=mid;
break;
}
if((mid*mid)<n)
{
start=mid+1;
ans=mid;
}
else
{
end=mid-1;
}
}
float dec=0.1;
for(int i=0;i<4;i++)
{
while(ans*ans<=n)
ans+=dec;
ans-=dec;
dec=dec/10;
}
return ans;
}
int main()
{
int n;
float ans;
printf("Enter the positive number\n");
scanf("%d",&n);
ans=sqt(n);
printf("square root is: %.4f\n",ans);
return 0;
}

