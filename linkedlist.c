
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int val,num;
struct node
{
	int data;
	struct node *next;
}*start,*ptr,*preptr,*newnode,*tmp;
typedef struct node node;
void create();
void insertbeg();
void insertend();
void deletebeg();
void deleteend();
void disp(); 
void main()
{
	int n;
		printf("MENU\n1.CREATION\n2.INSERT AT BEGENNING\n3.INSERT AT END\n4.DISPLAY\n5.DELETE FROM BEGENNING\n6.DELETE AT END\n7.EXIT\n");
		do
		{
		printf("Enter your option:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:create();
				break;
			case 2:insertbeg();
				break;
			case 3:insertend();
				break;
			case 4:disp();
				break;
			case 5:deletebeg();
				break;
			case 6:deleteend();
				break;
			case 7:exit(0);
		}
	}while(n!=11);
}
void create()
{
	int a;
	do
	{
		printf("Enter the data\n");
		scanf("%d",&num);
		newnode=(node*)malloc(sizeof(node));
		if(start==NULL)
		{
			newnode->data=num;
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			newnode->data=num;
			newnode->next=start;
			start=newnode;
		}
		printf("enter -1 for last node\n");
		scanf("%d",&a);
	}while(a!=-1);
}
void insertbeg()
{
	printf("Enter the data:");
	scanf("%d",&num);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=start;
	start=newnode;
}
void insertend()
{
	printf("Enter the data:\n");
	scanf("%d",&num);
	newnode=(node*)malloc(sizeof(node));
	newnode->data=num;
	newnode->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
		ptr->next=newnode;
 }
void disp()
{
		printf("data\n");
		ptr=start;
		while(ptr->next!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
}
void deletebeg()
{
	if(start==NULL)
		printf("underflow\n");
	else
	{
		ptr=start;
		start=start->next;
		free(ptr);
		printf("element deleted is:%d\n",ptr->data);
	}
}
void deleteend()
{
	if(start==NULL)
		printf("nderflow\n");
	else
	{
		ptr=start;
		preptr=ptr;
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=NULL;
		free(ptr);
	}
}


