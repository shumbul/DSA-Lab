/* prefix evaluation*/
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
		printf("\nStack Overflow.");
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
		printf("Stack Undeflow");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top--];
		return(item);
	}
}

void pre_evaluate(char pr[])
{
	int i,A,B,val;
	char ch;
	for(i=strlen(pr)-1;i>=0;i--)           //traversing from end
	{
		ch=pr[i];
		
		if(isdigit(pr[i]))
		{
		push(pr[i]-'0');
	        }
		
		else if (ch== '+' || ch== '-' || ch== '*' || ch== '/')
		{
			A = pop();
			B = pop();
			switch (ch)
			{
				case '*':
				val = A * B;
				break;

				case '/':
				val = A / B;
				break;

				case '+':
				val = A + B;
				break;

				case '-':
				val = A - B;
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
	char prefix[SIZE];
	int i;
	printf("\nEnter Prefix Expression: \n{one char in a line,write ')' to terminate} \n");
	for (i = 0 ; i < SIZE ; i++)
	{
		scanf("%c", &prefix[i]);

		if ( prefix[i] == ')' ) 
		{ break; } 
	}
	pre_evaluate(prefix);

	return 0;
}
