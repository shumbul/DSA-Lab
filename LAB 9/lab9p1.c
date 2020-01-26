#include <stdio.h>       //queue using linked list
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *front = NULL;
struct node *temp=NULL;
void push()
{
struct node *nn=(struct  node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&nn->data);
  if(front!=NULL)
  {
      temp->next=nn;
      temp=temp->next;
      temp->next=NULL;
  }
  else
  {
      front=nn;
      front->next=NULL;
      temp=front;
  }
  
}
void display()
{
    struct node *temp1;
    temp1 = front;
    if (temp1 == NULL)
    {
        printf("QUEUE EMPTY!\n");
        return;
    }
    printf("Elements in queue are\n");
    while (temp1 != NULL)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}   
void pop()
{
    struct node  *temp1;
    temp1=front;
    front=front->next;
    temp1->next=NULL;
    free(temp1);
}   
int main()
{
    int  op;  
    do
    {
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter option\n");
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
             display();
             break;
          case 4:
             break;
	  default:printf("Input is invalid\n");
        }
    } while (op !=4);
    return 0;
}         
