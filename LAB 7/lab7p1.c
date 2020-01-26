#include<stdio.h>
//infix to postfix
int isoperand(char x)
{	
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z')||(x>=0&&x<=9))		
	{		
		return 1;		
	}
	return 0;
}
 
int priority(char ch)
{	
	if(ch=='(')	
		return 5;	
	if(ch=='^')
		return 4;	
	if((ch=='*')||(ch=='/'))
		return 3;
	if((ch=='+')||(ch=='-')||(ch=='%'))
		return 2;
	if((ch=='<')||(ch=='>'))
		return 1;
}

void infixtopostfix()
{
int i=0,j=-1,top=-1,value;
	char postfix[100],infix[100],stack[100];
	printf("Enter the infix expression: \n");
	gets(infix);
	for(i=0;i<100;i++)
   stack[i]='\0'; 
   i=0;
	while(infix[i]!='\0')
	{
		if(isoperand(infix[i]))
		{
			postfix[++j]=infix[i];
		}
		else if(top==-1)
		{
		stack[++top]=infix[i];
		}
		
		else if(infix[i]=='(')
		{
		stack[++top]=infix[i];
		}
		
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
                         postfix[++j]=stack[top--];
			}
			
			top--; //for open bracket '('
		}
		else if(priority(infix[i])>priority(stack[top]))   
		 //if priority of operator is heigher than already existing operator, it can stay in the stack
		{
			stack[++top]=infix[i];		
		}
		else if(priority(infix[i])<=priority(stack[top]))
		//if not,put the already existing operator into postfix exp and then add the new operator from infix
		{
		    while((priority(infix[i])<=priority(stack[top]))&&top!=-1&&stack[top]!='(')
		    {		
			postfix[++j]=stack[top--];
		    }		
			top++;				
	                stack[top]=infix[i];		
		}
	i++;
 
	}
while(top!=-1)                //for the elements left in the stack
{
postfix[++j]=stack[top--];
}
printf("The postfix expression is: \n");
puts(postfix);
} 
int main()
{	
 infixtopostfix();
 printf("\n");	
 return 0;
} 
