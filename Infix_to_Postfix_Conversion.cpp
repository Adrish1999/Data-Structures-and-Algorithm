#include <stdio.h>
#include <stdlib.h>

char stack[80];
int top=-1;

void push(char x)
{
	stack[++top]=x;
}

char pop()
{
	if(top==-1)
	return -1;
	return stack[top--];
}

int prec(char x)
{
	if(x=='(')
	return 0;
	else if(x=='+'||x=='-')
	return 1;
	else if(x=='*'||x=='/')
	return 2;
}

int isalpnum(char x)
{
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9'))
	return 1;
	else 
	return 0;	
}

int main()
{
	char *e,exp[80],x;
	printf("Enter the infix expression\n");
	scanf("%s",exp);
	e=exp;
	printf("\nThe postfix expression is :\n");
	while(*e!='\0')
	{
		if(isalpnum(*e))
		printf("%c",*e);
		else if(*e=='(')
		push(*e);
		else if(*e==')')
		{
			while((x=pop())!='(')
			printf("%c",x);
		}
		else
		{
			while(prec(stack[top])>=prec(*e))
			printf("%c",pop());
			push(*e);
		}
		e++;
	}
		while(top!=-1)
		printf("%c",pop());
}
