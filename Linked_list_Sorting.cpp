#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}N;

N *start;

void insert_at_end(int v)
{
	N *nu=(N*)malloc(sizeof(N)),*ptr;
	nu->data=v;
	nu->link=NULL;
	if(start==NULL)
	{
		start = nu;
		return;
	}
	for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
	ptr->link=nu;
}


void insert_at_beg(int v)
{
	N *nu=(N*)malloc(sizeof(N));
	nu->data=v;
	nu->link=start;
	start=nu;
}


void insert_at_posi(int p,int v)
{
	N *nu = (N*)malloc(sizeof(N)),*ptr,*prev;int c=0;
	nu->data=v;
	ptr=prev=start;
	if(p==1)
	{
		nu->link=start;
		start=nu;
		return;
	}
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c+1)
	{
		printf("Invalid position to insert\n");
		return;
	}
	nu->link=ptr;
	prev->link=nu;
}


void del_from_end()
{
	N *ptr,*prev;int c=0;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr=prev=start;
	while(ptr->link!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr==start)
	start=NULL;
	else
	prev->link=NULL;
	printf("Deleted item is %d\n",ptr->data);
	free(ptr);
}


void del_from_beg()
{
	N *ptr;
	if(start==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	ptr=start;
	start=start->link;
	printf("Deleted item is %d\n",ptr->data);
	free(ptr);
}


void del_from_posi(int p)
{
	int c=0;
	N *ptr,*prev;
	if(start==NULL)
	{
		printf("The list is empty\n");
		return;
	}
	while(ptr!=NULL)
	{
		c++;
		if(c==p)
		break;
		prev=ptr;
		ptr=ptr->link;
	}
	if(p>c)
	{
		printf("Invalid position to delete\n");
		return;
	}
	if(ptr==start)
	start=start->link;
	else
	prev->link=ptr->link;
	printf("Deleted item is %d\n",ptr->data);
	free(ptr);
}


void display()
{
	N *ptr=start;
	printf("\nThe linked list:\n");
	if(start==NULL)
	{
		printf("Empty");
		return;
	}
	while (ptr->link!=NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->link;
	}
	printf("%d\n",ptr->data);
	printf("\n");
}


int count()
{
	int c=0;N *ptr;
	for(ptr=start;ptr!=NULL;ptr=ptr->link)
	c++;
	return c;	
}

void sort()
{
	int n=count();
	int i,temp,j;N *ptr;
	for(i=0;i<n;i++)
	{
		ptr=start;
		for(j=0;j<n-i-1;j++)
		{
			if(ptr->data>ptr->link->data)
			{
				temp=ptr->data;
				ptr->data=ptr->link->data;
				ptr->link->data=temp;
			}
		ptr=ptr->link;
		}	
	}
	display();
}


int main()
{
	int ch,ch1,v,p;
	while(1)
	{
		printf("Enter 1 / 2 / 3 / 4 / 5 to insert / delete / display / sort the list / exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				printf("Enter 1/2/3 to insert at end/beginning/given position\n");
				scanf("%d",&ch1);
				printf("Enter the data to insert\n");
				scanf("%d",&v);
				printf("\n");
				switch(ch1)
				{
					case 1:
						insert_at_end(v);
						display();
						break;
					case 2:
						insert_at_beg(v);
						display();
						break;
					case 3:
						printf("Enter the position to insert\n");
						scanf("%d",&p);
						insert_at_posi(p,v);
						display();
						break;
				    default:printf("Enter correct choice\n");
				}
			break;
			case 2:
				printf("\nPress 1/2/3 to delete from end/beginning/position\n");
				scanf("%d",&ch1);
				printf("\n");
				switch(ch1)
				{
					case 1:
						del_from_end();
						display();
						break;
					case 2:
						del_from_beg();
						display();
						break;
					case 3:
						printf("\nEnter the position:");
						scanf("%d",&p);
						del_from_posi(p);
						display();
						break;
					default:
						printf("\nEnter correct choice");
				}
			break;
			case 3:
				display();
			break;
			case 4:
				printf("After sorting\n\n");
				sort();
			break;
			case 5:
				printf("\nThank You!!!Visit Again!!!");
				return 0;
			default:
				printf("\nEnter correct choice");
		}
	}
}
				
		
	
