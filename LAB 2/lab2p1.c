#include<stdio.h>
#include<stdlib.h>
int selectionsort(int *arr,int n)
{
    int i,j,temp;
for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)         //main sorting method
        {
            if(*(arr+i)>*(arr+j))  //comparing values in the arrays and if condition satsfies, swapping
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+i);
                *(arr+i)=temp;
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
    selectionsort(arr,n);
    printf("Sorted elements are\n");
    for(i=0;i<n;i++)
        printf("%d\n",*(arr+i));
return 0;
}
