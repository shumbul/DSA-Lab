//loop in linked list
#include <stdio.h>     
#include <stdlib.h>
#include <malloc.h>
struct node {
    int data;
    struct node * next;
}*head;

void createList(int n)
{
    int i, data;
    struct node *newNode,*temp;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->next = NULL;

            temp = head;
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->next = NULL;
					temp->next = newNode; // Link previous node with the new node
                    temp = newNode;       // Make new node as last/previous node
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}
void displaylist()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("no elements\n");
        return;
    }
    printf("elements in linked list are\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void createloop()
{
int i,pos;
printf("Enter the position you want to make loop at\n");
scanf("%d",&pos);
struct node *p,*temp;
temp=p=head;
for(i=1;i<pos;i++)
{
temp=temp->next;  //temp point at the given position
}
while(p->next!=NULL)
p=p->next;      //p points to the end of the linked list
p->next=temp;
printf("LOOP SUCCESSFULLY CREATED!\n");
}
void checkloop()
{
struct node *fast,*slow;
fast=slow=head;
int flag=0;
while (slow && fast && fast->next) { 
slow=slow->next;
fast=fast->next->next;
if(fast==slow)
{
printf("LOOP FOUND\n");
flag=1;
break;
}
}
if (flag==0)
printf("LINKED LIST IS FREE OF LOOPS\n");
}
void delloop()
{
struct node *fast,*slow,*temp;
temp=head;
fast=slow=head;
while(slow->next!=NULL)
{
slow=slow->next;
fast=fast->next->next;
if(fast==slow)
{
break;}
}
temp=fast;
while(temp->next!=fast)
{
temp=temp->next;
}
temp->next=NULL;
printf("LINKED LIST IS NOW LOOP FREE\n");
}
void insertpos()
{
struct node *temp;
int pos,val;
struct node *nn=(struct  node*)malloc(sizeof(struct node));
  printf("enter the position\n");
  scanf("%d",&pos);
  printf("enter the data\n");
  scanf("%d",&val);
  nn->data=val;
  if(head!=NULL)
  {
      temp=head;
      if (pos==1)
      {
      nn->next=temp;
      head=nn;
      }
      else
      {
      for(int i=1;i<pos-1;i++)
      temp=temp->next;
      nn->next=temp->next;
      temp->next=nn;
      }
  }
  printf("\nElement successfully inserted\n");
  displaylist();
}

int main()
{
    int n, choice;

    head = NULL;
    
    printf("Enter the number of nodes you want to create: \n");
    scanf("%d", &n);

    createList(n);

    do{
	printf("\nPress 1 to display list\nPress 2 to create a loop\nPress 3 to delete loop\nPress 4 to check for loop in the list\nPress 5 to insert\nPress 6 to EXIT\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
        	case 1:displaylist();
    		break;
    		case 2:createloop();
    		break;
    		case 3:delloop();
    		break;
    		case 4:checkloop();
    		break;
    		case 5:insertpos();
    		break;
    		case 6:break;
	        default:printf("Input is invalid\n");
    }
    }while(choice!=5);
    return 0;
}
