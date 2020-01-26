//Binary Tree Implementation
#include<stdio.h>
#include<stdlib.h>

struct node
{ 
int data;
struct node* left;
struct node* right;
}* root=NULL;
int flag=0,key=0;            //used in deletion and search

struct node* insertion(struct node* root,int data)
{
  if(root==NULL)
   {
    root=(struct node*)malloc(sizeof(struct node));
     root->data=data;
     root->left=root->right=NULL;
     printf("%d successfully inserted\n",root->data);
   }
   else {if(data>root->data)
     root->right= insertion(root->right,data);
      else if(data<root->data)
     root->left= insertion(root->left,data);}
    return root;
}
 
struct node* getmax(struct node*root)
{
    if(root==NULL)
    return root;
    if(root->right==NULL)
    {
    return root;
    }
    return getmax(root->right); 
}

struct node* deletion(struct node*root, int data)
 { 
    if(data>root->data)
    {
    root->right=deletion(root->right,data);
    }
    else if(data<root->data)
    {
    root->left= deletion(root->left,data);
    }   
    else
    {
    if(root->right==NULL)
    {
    struct node* temp=root->left;
    free(root);
    return temp;
    }
    if(root->left==NULL)
    {
    struct node* temp=root->right;
    free(root);
    return temp;
    }
    struct node* temp=getmax(root->left);   
    root->data=temp->data;
    root->left=deletion(root->left,temp->data);
    }
    return root;
 }
 
struct node* search(struct node*root, int data)
 { 
    if(data==root->data)
    {
    printf("%d found",root->data);
    return root;
    }
    else if(data>root->data)
    {
    printf("Moving right of %d\n",root->data);
    search(root->right,data);
    }
    else if(data<root->data)
    {
    printf("Moving left of %d\n",root->data);
    search(root->left,data);
    }
    else return NULL;
 }
//TRAVERSALS
void inorder(struct node* root)
{
    
    if(root==NULL)
    return ;
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{

 if(root==NULL)
  return;
  else
  {
      printf("%d\t",root->data);
      preorder(root->left);
      preorder(root->right);
  }
}
void postorder(struct node* root)
{

if(root==NULL)
 return;
 else
 {
     postorder(root->left);
     postorder(root->right);
     printf("%d\t",root->data);
 }
}

int size(struct node * root)
{
if(root==NULL)
return 0;

return 1+size(root->left)+size(root->right);
}

int iscomplete(struct node* root,int i,int n)
{
if(root==NULL)
return 1;

if ((root->left&&2*i+1>=n)||!iscomplete(root->left,2*i+1,n))
return 0;
if ((root->right&&2*i+2>=n)||!iscomplete(root->right,2*i+2,n))
return 0;
return 1;
}
int main()
 {
  int d,data;
  while(1)
 {
    printf("\nEnter your choice:\n1.insertion \n2.deletion \n3.traverse\n4.search\n5.complete tree or not\n6.exit\n");
    scanf("%d",&d);
    switch(d)
    {
        case 1:
               printf("Enter data to be inserted\n");
               scanf("%d",&data);
               root=insertion(root,data);
               break;
        case 2:
               if (root==NULL)
               {
               printf("Tree is empty\n");
               }
               else
               {
               printf ("Enter data to be deleted\n");
               scanf("%d",&data);
               root=deletion(root,data);
               }
               flag=0;
               break;
        case 3:
                printf("INOREDER:\n");
                 inorder(root);
                printf("\nPREOREDER:\n");
                 preorder(root);
                printf("\nPOSTOREDER:\n");
                 postorder(root);
                break;
        case 4:
               if (root==NULL)
               {
               printf("Tree is empty\n");
               }
               else
               {
               printf ("Enter data to be searched\n");
               scanf("%d",&data);
               root=search(root,data);
               if (root==NULL)
               printf("The element you wanted to search is not present, Please Try Again\n");
               }
               key=0;
               break;
        case 5: 
               flag=iscomplete(root,0,size(root));  
               if(flag==1)
               printf("YES\n");
               else 
               printf("NO\n");
               break;
        case 6: 
                exit(0);
                break;
        default:printf("wrong input");
    }
    }
 }
