#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;
void search();
void insert();
void del();
void createList(int n);
void displayListFromFirst();
void displayListFromEnd();

int main()
{
    int n, choice;

    head = NULL;
    last = NULL;
    
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    createList(n);

    do{
	printf("\nPress 1 to display list from First\nPress 2 to display list from End\nPress 3 to insert an element\nPress 4 to delete an element\nPress 5 to search in the list\nPress 6 to EXIT\n");
    scanf("%d", &choice);

    switch(choice)
    {
        	case 1:displayListFromFirst();
    		break;
    		case 2:displayListFromEnd();
    		break;
    		case 3:insert();
    		break;
    		case 4:del();
    		break;
    		case 5:search();
    		break;
    }
    }while(choice!=6);
    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;       // Make new node as last/previous node
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}
void displayListFromFirst()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void displayListFromEnd()
{
    struct node * temp;
    int n = 0;

    if(last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of last-%d node = %d\n", n, temp->data);
            n++;
            temp = temp->prev; 
        }
    }
}
void insert()
{
        int pos,i=1,num;
		struct node *newNode,*temp;
        temp=head;
        printf("Enter position\n");
        scanf("%d",&pos);
		printf("Input data for the node: ");
        scanf("%d", &num);
        while(i<pos-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(pos== 1)
        {
        	newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = num;
        newNode->next = head; 
        newNode->prev = NULL; 
		head->prev = newNode;
		head = newNode;
	    }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = num;
            newNode->next = temp->next; 
            newNode->prev = temp;       

            if(temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;

            printf("NODE INSERTED SUCCESSFULLY AT %d POSITION\n", pos);
        }
        else
        {
            printf("Error, Invalid position\n");
        }
}
void del()
{
	int pos,i;
	struct node *p=NULL;
	printf("Enter position\n");
        scanf("%d",&pos);
        p=head;
        for(i=1;i<pos&&p!=NULL;i++)
        {
        	p=p->next;
		}
		if(p!=NULL)
		{
		p->prev->next=p->next;
		p->next->prev=p->prev;
		free(p);
	}
}
void search()
{
    struct node *temp;
	int n,count=0;
	temp=head;
	printf("Enter the number to be searched\n");
	scanf("%d",&n);
	if(head==NULL)
	{
		printf("It's an empty linked list ");
    }
	else{
	while(temp!=NULL)
	{
		count++;
		if(temp->data ==n)
		printf("the number found at position %d\n",count);
	    temp=temp->next;
    }
    }
}
