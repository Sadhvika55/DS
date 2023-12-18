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
void search(struct node *head, int search);
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
    search(head,20);
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
void search(struct node *head,int search)
{
    struct node *temp=NULL;
    temp=head;
    while(head!=NULL)
    {
        if(temp->data==search)
        {
            printf("serach=%d",search);
            break;
        }
        else
        {
            temp=temp->next_link;
        }
    }
}
