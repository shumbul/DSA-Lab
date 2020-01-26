#include<stdio.h>
#include<stdlib.h>
int bubblesort(int *arr,int n)
{
    int i,j,temp,max;
for(i=1;i<n;i++)
{
            for(j=0;j<n-i;j++)
            if(*(arr+j)>*(arr+j+1))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    return 0;
}
 
int main()
{
    int *arr,n,i;
    printf("Enter no. of elements\n");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",(arr+i));
    bubblesort(arr,n);
    printf("Sorted elements are\n");
    for(i=0;i<n;i++)
        printf("%d\n",*(arr+i));
return 0;
}
