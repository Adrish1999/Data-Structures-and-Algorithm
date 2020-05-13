#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}N;

N *front=NULL , *rear=NULL;

void insert(int v)
{
	N *nu = (N*)malloc(sizeof(N));
	nu->data=v;
	nu->link=NULL;
	if(front==NULL)
	front=rear=nu;
	else
	{
		rear->link=nu;
		rear=nu;
	}
	rear->link=front;
}

int dequeue()
{
	int x;
	if(front==NULL)
	return -1;
	else if(front==rear)
	{
		x=front->data;
		free(front);
		front=rear=NULL;
	}
	else
	{
		N *ptr=front;
		x=ptr->data;
		front=front->link;
		rear->link=front;
	}
	return x;
}

int empty()
{
	if(front==NULL)
	return 1;
	else
	return 0;
}

void display()
{
	if(empty())
	{
		printf("\nQueue is empty\n");
	}
	N *ptr=front;
	printf("\nThe Circular linked list is\n");
	do
	{
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}while(ptr!=front);
	printf("\n\n");
}

int main()
{
	int n,ch,p;
	while(1)
	{
		printf("Enter 1/2/3/4 to push/pop/display/exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter data\n");
				scanf("%d",&n);
				insert(n);
				break;
			case 2:
				p=dequeue();
				if(!(empty()))
				printf("Deleted item is %d \n",p);
				else
				printf("Empty queue\n");
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
