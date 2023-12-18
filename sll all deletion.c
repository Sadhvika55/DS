/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *link;
};
struct node *delbegin(struct node *head)
{
  struct node *temp=head;
  int pos=1;
  if(pos==1)
  {
    head=temp->link;
    free(temp);
  }
  temp=NULL;
  return head;
}
void delend(struct node *head)
{
  struct node *temp=NULL;
  temp=head;
  while(temp->link->link!=NULL)
  {
    temp=temp->link;
  }
  struct node *temp1=NULL;
  temp1=temp->link;
  temp->link=NULL;
  free(temp1);
}
void delran(struct node *head,int pos)
{
  struct node *temp=head;
  struct node *new=head;
  if(pos==1)
  {
    head=temp->link;
    free(temp);
  }
  else
  {
    while(pos!=1)
    
	{
		
      new=temp;
      temp=temp->link;
      pos--;
    }
    new->link=temp->link;
    free(temp);
    temp=new;
  }
}
void traverse(struct node *head)
{
  struct node *temp=head;
  if(head==NULL)
  {
    printf("list is empty");
  }
  while(temp!=NULL)
  {
    printf("%d->",temp->data);
    temp=temp->link;
  }
}
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
  current->link=  NULL;
  head->link->link=current;
  current=(struct node*)malloc(sizeof(struct node));
  current->data=40;
  current->link=  NULL;
  head->link->link->link=current;
  printf("linked list:");
  traverse(head);
  printf("\n Delete at begin:");
  head=delbegin(head);
  traverse(head);
  printf("\n Delete at random:");
  delran(head,2);
  traverse(head);
  printf("\n Delete at end");
  delend(head);
  traverse(head);
}
