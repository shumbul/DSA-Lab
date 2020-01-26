#include <stdio.h>       //stack using linked list
#include <stdlib.h>
int top=-1,n,k=0;

void push(int a[])
{
	if(top==n-1)
	printf("STACK OVERFLOW\n");
	else{
		int data;
		printf("Enter the data\n");
		scanf("%d",&data);
		a[++top]=data;
		printf("DATA PUSHED SUCCESSFULLY\n");
	}
	
}

void pop(int a[])
{
	if(top==-1)
	printf("STACK UNDERFLOW\n");
	else{
		top--;
	}
	printf("Top successfully popped\n");
}

void display(int a[])
{
	int i;
	printf("DISPLAYING elements in stacks:\n");
	if(top==-1)
	printf("STACK EMPTY\n");
	else{
		for (i=k-1;i>=0;i--)
		printf("%d\n",a[i]);
	}
}

void peek(int a[])
{
if(top==-1)
printf("STACK EMPTY\n");
else
printf("The peek element is: %d\n",a[top]);
}

void search(int a[])
{
int t,flag=0,i;
printf("ENTER THE ELEMENT YOU WANT TO SEARCH \n");
scanf("%d",&t);
for (i=0;i<n&&i<k;i++)
{
if(a[i]==t)
{
flag=1;
printf("Element found at %d\n",i+1);
}
}
if(flag==0)
printf("Element not present in the given stack\n");
}

int main()
{
	printf("enter the stack maximum capacity\n");
	scanf("%d",&n);
	int  op,a[n];  
    do
    {
        printf("1.push\n2.pop\n3.peek\n4.search\n5.display\n6.exit\n");
        printf("enter option\n");
        scanf("%d", &op);
        switch (op)
        {
          case 1:
             push(a);
             k++;
             break;
          case 2:
             pop(a);
             k--;
             break;
          case 3:
             peek(a);
             break;
          case 4:
             search(a);
             break;
          case 5:
             display(a);
             break;
          case 6:
             break;
	  default:printf("Input is invalid\n");
        }
    } while (op !=6);

return 0;	
}
