/* postfix evaluation*/
#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>       /* for isdigit and isalpha */
#include<string.h>

#define SIZE 100


int stack[SIZE];
int top = -1;

void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.\n");
	}
	else
	{
		stack[++top] = item;
	}
}

int pop()
{
	int item ;

	if(top <0)
	{
		printf("Stack Undeflow.\n");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top--];
		return(item);
	}
}

void post_evaluate(char po[])
{
	int i,A,B,val;
	char ch;
	for(i=0;po[i]!=')';i++)
	{
		ch=po[i];
		
		if(isdigit(po[i]))
		push(po[i]-'0');
		
		else if (ch== '+' || ch== '-' || ch== '*' || ch== '/')
		{
			A = pop();
			B = pop();
			switch (ch)
			{
				case '*':
				val = B * A;
				break;

				case '/':
				val = B / A;
				break;

				case '+':
				val = B + A;
				break;

				case '-':
				val = B - A;
				break;
			}

			push(val);
		}
		
	}
		val=pop();
		printf("output: %d\n",val);
}
int main()
{
	char postfix[SIZE];
	int i;
	printf("\nEnter Postfix Expression: \n{one char in a line,write ')' to terminate} \n");
	for (i = 0 ; i < SIZE ; i++)
	{
		scanf("%c", &postfix[i]);

		if ( postfix[i] == ')' ) 
		{ break; } 
	}
	post_evaluate(postfix);

	return 0;
}
