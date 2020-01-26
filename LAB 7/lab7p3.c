//postfix to prefix
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char str[MAX],stack[MAX];
int top=-1;
void rev(char s[])
{
int n=strlen(s);
int i;
for(i=0;i<n/2;i++)
{
char temp=s[i];
s[i]=s[n-i-1];
s[n-i-1]=temp;
}
}
void push(char c)
{
   stack[++top]=c;
}
char pop()
{
   return stack[top--];
}
void post_pre()
{
   int n,i,j=0;
   char c[100];
   char a,b,op;
   printf("Enter the postfix expression\n");
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0'; //made all the values of stack as NULL
   printf("Prefix expression is:\t");
   //traversing from end to start in the given postfix expression
   for(i=n-1;i>=0;i--)
   {
      //if an operator,pushing it in the stack
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      //if an operand ,adding the operand to c
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop();
            c[j++]=pop();
        }
        push('@');  //when the next time it sees an operand
      }
   }
   c[j]='\0'; //terminating c
   rev(c);
   printf("%s",c);
}
int main()
{
    post_pre();
    printf("\n");
    return 0;
}
