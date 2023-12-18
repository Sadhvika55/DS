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
struct node* del_beg(struct node *head);
void del_last(struct node *head);
struct node* del_random(struct node *head,int pos);
void display(struct node *head);
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
    current=(struct node*)malloc(sizeof(struct node));
    current->prev_link=NULL;
    current->data=40;
    current->next_link=NULL;
    head->next_link->next_link->next_link=current;
    printf("before deletion\n");
    display(head);
    printf("deletion at begin\n");
    head=del_beg(head);
    display(head);
    printf("\nAfter deletion at end:\n");
	del_last(head);
	display(head);
	
	printf("\nAfter deletion at ran:\n");
	head=del_random(head,2);
	display(head);
}
void display(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        printf("link is empty\n");
    }
    while(temp!=NULL)
    {
        printf("%d=>",temp->data);
        temp=temp->next_link;
    }
    printf("NULL\n");
}
struct node* del_beg(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    head=temp->next_link;
    free(temp);
    head->prev_link=NULL;
    return head;
}
void del_last(struct node *head)
{
    struct node *temp=NULL;
    temp=head;
    while(temp->next_link->next_link!=NULL)
    {
        temp=temp->next_link;
        
    }
    free(temp->next_link);
    temp->next_link=NULL;
    

}
struct node* del_random(struct node *head,int pos)
{
    struct node *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        printf("link is empty\n");
    }
    if(pos==1)
    {
        head=temp->next_link;
        free(temp);
        head->prev_link=NULL;
    }
    else
    {
        while(1>pos)
        {
            temp=temp->next_link;
            pos--;
        }
        temp->prev_link->next_link=temp->next_link;
        temp->next_link->prev_link=temp->prev_link;
        free(temp);
        
        return head;
    }
    
}



