#include <stdio.h>       //circular linked list
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *first = NULL;

void  insert()
{
struct node *temp;
struct node *nn=(struct  node*)malloc(sizeof(struct node));
  printf("enter  the data\n");
  scanf("%d",&nn->data);
  if(first!=NULL)
  {
      temp=first;
      while(temp->next!=first)
        temp=temp->next;
      temp->next=nn;
  }
  else
  {
      first=nn;
  }
  nn->next=first;
}
void insertpos()
{
struct node *temp,*preptr,*postptr;
int pos,val;
struct node *nn=(struct  node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&val);
  printf("enter the position\n");
  scanf("%d",&pos);
  if(first!=NULL)
  {
      temp=first;
      if (pos==1)
      {
      nn->data=val;
      nn->next=temp;
      first=nn;
      }
      else
      {
      for(int i=0;i<pos-1;i++)
      {
      preptr=temp;
      temp=temp->next;
      }
     preptr->next=nn;
     nn->data=val;
      nn->next=temp;
  }
  }
  else
  {
      insert();
  }
}

void display()
{
    struct node *temp;
    temp = first;
    if (temp == NULL)
    {
        printf("no elements\n");
        return;
    }
    printf("elements in linked list are\n");
    printf("%d\n", first->data);
    temp=temp->next;
    while (temp != first)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void deletion()
{
    struct node  *temp;
    temp = first;
    first = first->next;
    temp->next = NULL;
}
void deletionpos()
{
    struct node  *temp,*preptr,*postptr;
    int pos;
    temp = first;
    printf("enter the position\n");
    scanf("%d",&pos);
      for(int i=0;i<pos-1;i++)
      {
      preptr=temp;
      temp=temp->next;
      postptr=temp->next;
      }
     preptr->next=postptr;
      free(temp->next);
  
  
}
void count()
{
	struct node *temp;int n;
	temp=first;
	if(first==NULL)
	{
		printf("0");
		return;
	}
	n=1;
	while(temp->next!=NULL)
	{
		n++;temp=temp->next;
	}
	printf("Number of nodes\n");
	printf("%d\n",n);
}
void search()
{
	struct node *temp;int n,count=0;
	temp=first;
	printf("enter the number to be searched\n");
	scanf("%d",&n);
	if(first==NULL)
	{
		printf("It's an empty linked list ");
		return;
	}
	while(temp->next!=first)
	{
		count++;
		if(temp->data==n)
		printf("the number found at position %d\n",count);
		temp=temp->next;
	}
	
	
}

int main()
{
    int  op;  
    do
    {
        printf("1.insertion\n2.insert at specified position\n3.deletion\n4.delete from specified position\n5.display\n6.count\n7.search\n8.exit\n");
        printf("enter option\n");
        scanf("%d", &op);
        switch (op)
        {
          case 1:
             insert();
             break;
          case 2:
             insertpos();
             break;
          case 3:
             deletion();
             break;
          case 4:
             deletionpos();
             break;
          case 5:
             display();
             break;
	  case 6:
	     count();
	     break;
	     case 7:
             search();
             break;
	  case 8:break;
	  default:printf("Input is invalid\n");
        }
    } while (op !=8);
    return 0;
}
