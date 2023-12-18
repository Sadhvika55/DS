/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void travers_node(struct node *head);
void revers_node(struct node *head);
void main()
{
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=10;
	head->link=NULL;
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=20;
	current->link=NULL;
	head->link=current;
	current=(struct node*)malloc(sizeof(struct node));
	current->data=30;
	current->link=NULL;
	head->link->link=current;
	travers_node(head);
	revers_node(head);
}
void travers_node(struct node *head)
{
	struct node *temp=NULL;
	temp=head;
	if(temp==NULL)
	{
		printf("List is empty");
	}
	while(temp!=NULL)
	{
		printf("%d--",temp->data);
		temp=temp->link;
	}
}
void revers_node(struct node *head)
{
	struct node *temp1=NULL;
	struct node *temp2=NULL;
	while(head!=NULL)
	{
		temp2=head->link;
		head->link=temp1;
		temp1=head;
		head=temp2;
	}
	head=temp1;
	printf("\nAfter reversing the node\n");
	travers_node(head);
}

