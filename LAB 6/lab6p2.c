#include <stdio.h>       //stack using linked list
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push()
{
struct node *temp;
struct node *nn=(struct  node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&nn->data);
  if(top!=NULL)
  {
      temp=top;
      nn->next=top;
      top=nn;
  }
  else
  {
      top=nn;
      nn->next=NULL;
  }
  
}

void display()
{
    struct node *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("STACK EMPTY\n");
        return;
    }
    printf("elements in stack are\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}               

void pop()
{
    struct node  *temp;
    if(top!=NULL)
    {
    temp = top;
    top = top->next;
    free(temp);
    }
    else
    printf("STACK UNDERFLOW\n");
}

void peek()
{
    if (top == NULL)
    {
        printf("STACK EMPTY\n");
        return;
    }
    else
    printf("The peek element is: %d\n",top->data);
}

void search()
{
struct node *temp;
int n,count=0;
	temp=top;
	if(top==NULL)
	{
		printf("STACK EMPTY\n");
		return;
	}
	printf("Enter the number to be searched\n");
	scanf("%d",&n);
	while(temp->next!=NULL)
	{
		count++;
		if(temp->data==n)
		printf("The number found at position %d\n",count);
		temp=temp->next;
	}
}
int main()
{
    int  op;  
    do
    {
        printf("1.push\n2.pop\n3.peek\n4.search\n5.display\n6.exit\n");
        printf("enter option\n");
        scanf("%d", &op);
        switch (op)
        {
          case 1:
             push();
             break;
          case 2:
             pop();
             break;
          case 3:
             peek();
             break;
          case 4:
             search();
             break;
          case 5:
             display();
             break;
          case 6:
             break;
	  default:printf("Input is invalid\n");
        }
    } while (op !=6);
    return 0;
}
