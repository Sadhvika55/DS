/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev_link;
    int data;
    struct node *next_link;
};
void travers(struct node *head);
struct node* insert_beg(struct node *head,int data);
void insert_random(struct node *head, int data,int pos);
void insert_last(struct node *head,int data);
void main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->prev_link=NULL;
    head->data=10;
    head->next_link=NULL;
    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->prev_link=NULL;
    current->data=20;
    current->next_link=NULL;
    head->next_link=current;
    current=(struct node*)malloc(sizeof(struct node));
    current->prev_link=NULL;
    current->data=30;
    current->next_link=NULL;
    head->next_link->next_link=current;
    printf("before reversing\n");
    travers(head);
    printf("inserting at begin\n");
    head=insert_beg(head,40);
    travers(head);
    printf("inserting at last\n");
    insert_last(head,50);
    travers(head);
    insert_random(head,60,3);
    
}
void travers(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        printf("link is empty\n");
    }
    while(temp!=NULL)
    {
        printf("%d<=>",temp->data);
        temp=temp->next_link;
    }
    printf("NULL\n");
}
struct node* insert_beg(struct node *head,int data)
{
    struct node *temp=NULL;
    temp=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->prev_link=NULL;
    new->data=data;
    new->next_link=NULL;
    new->next_link=temp;
    
    return new;
}
    
void insert_last(struct node *head,int data)
{
    struct node *temp=NULL;
    temp=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->prev_link=NULL;
    new->data=data;
    new->next_link=NULL;
    while(temp->next_link!=NULL)
    {
        temp=temp->next_link;
    }
    temp->next_link=new;
    new->prev_link=temp;

}

void insert_random(struct node *head, int data,int pos)
{
    struct node *temp=NULL;
    temp=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->prev_link=NULL;
    new->data=data;
    new->next_link=NULL;
    while(pos!=1)
    {
        temp=temp->next_link;
        pos--;
    }
    new->next_link=temp->next_link;
    temp->next_link=new;
    new->prev_link=temp;
    printf("insertion at random\n");
    travers(head);
    
}