#include<stdio.h>
#define MAX 50

int stack[MAX],top=-1;

void push(int v)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow\n");
		return;
	}
	stack[++top]=v;
}
void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n");
		return;
	}
	printf("Deleted item is %d\n",stack[top]);
	top--;
}
void display()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("The stack elements are \n");
	int i;
	for(i=top;i>=0;i--)
	printf("%d ",stack[i]);
	printf("\n");
}
int main()
{
	int n,ch;
	while(1)
	{
		printf("Enter 1/2/3/4 to push/pop/display/exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
			    break;
			case 4:
				return 0;
				break;
			default:printf("Wrong choice plz enter again\n");
		}
		
	}
}
