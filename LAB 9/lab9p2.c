#include <stdio.h>       //circular queue using arrays
#include <stdlib.h>
int front=-1,rear=0,i=0;
void enqueue(int a[],int n)
{
	int val;
	
	if((rear==n-1&&front==0)||rear==(front-1)%(n-1))   
	printf("QUEUE IS FULL\n");
	
	else{
	printf("enter the element to be inserted\n");
	scanf("%d",&val);
	
	if(front==-1&&rear==n-1)                           //inserting the 1st element
	{
		front=rear=0;
		a[rear]=val;
	}
	
	else if(rear==n-1 &&front!=0)                      //rear reaches end but space is there
	{
		rear=0;
		a[rear]=val;
	}
	
	else
	{
	    a[++rear]=val;
	}
}
}
int dequeue(int a[],int n)
{
	int data;
	if (front==-1)
	{
	printf("QUEUE UNDERfLOW\n");
	return 0;
        }  

        else if(front==rear)     //when there is only a single element in queue
        {
        data=a[front];
    	front=rear=-1;
    	return data;
	}
	else if(front==n-1)      //when front is at the end   
	{
	data=a[front];	
	front=0;
	return data;
        }
	else {
		data=a[front];	
	front++;
	return data;
        }
}
	
void display(int a[],int n)
{
	int j;
	printf("DISPLAYING elements in queue:\n");
	if(front==-1||front==rear-1)
	printf("QUEUE EMPTY\n");
	else if(front>rear)
	{
		for (j=front;j<=n-1;j++)
		printf("%d\t",a[j]);
		for (j=0;j<=rear;j++)
		printf("%d\t",a[j]);
	}
	else{
		for (j=front;j<=rear;j++)
		printf("%d\t",a[j]);
	}
	printf("\n");
}

int main()
{
	
	int n,data;
	printf("Enter the maximum capacity of queue\n");
	scanf("%d",&n);
	rear=n-1;
	int  op,a[n];  
    do
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("Enter option\n");
        scanf("%d", &op);
        switch (op)
        {
          case 1:
             enqueue(a,n);
             break;
          case 2:
             data=dequeue(a,n);
             if(data!=0)
             printf("%d got deleted\n",data);
             break;
          case 3:
             display(a,n);
             break;
          case 4:
             break;
	  default:printf("Please enter a valid input!\n");
        }
    } while (op !=4);

return 0;	
}
