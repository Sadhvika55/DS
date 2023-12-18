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
struct node *top=NULL;
int isempty()
{
	return top==NULL;
}
int push(int data)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->link=NULL;
	new->link=top;
	top=new;
	return top->data;
}
int pop()
{
	if(isempty())
	{
		printf("stack is underflow" );
	}
	else
	{
		struct node *temp=top;
		top=temp->link;
		free(temp);
	}
	return top->data;
}
int peek()
{
	if(isempty())
	{
		printf("stack is underflow");
	}
	else
        return top->data;
	
}
void display()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("stack is empty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}
int main()
{
	push(10);
	push(20);
	push(30);
	printf("Initial stack value\n");
	display();
    printf("Top value=%d",peek());
	printf("\npop value\n");
	pop();
	pop();
	display();
	
}
