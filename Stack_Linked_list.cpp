#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}N;

N *top;

void push(int d)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=d;
	nu->link=top;
	top=nu;
}


void pop()
{
	if(top==NULL)
	{
		printf("Stack underflow\n");
		return;
	}
	else
	printf("Deleted item is %d \n",top->data);
	top=top->link;
}


void display()
{
	if(top==NULL)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("The stack elements are\n");
	N *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->link;
	}
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
