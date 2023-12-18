#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void traverse(struct node *head)
{
    struct node *temp=NULL;
    temp=head->link;
    if(head==NULL)
    {
        printf("link is empty\n");
    }
    do 
    {
        printf("%d<=>",temp->data);
        temp=temp->link;
    }
    while(temp!=head->link);
    {
       printf("%d",temp->data);
    }
}
struct node* insert_begin(struct node *head,int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    new->link=head->link;
    head->link=new;
    return head;
}
struct node* insert_last(struct node *head,int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    new->link=head->link;
    head->link=new;
    head=head->link;
    return head;
}
struct node* insert_random(struct node *head,int data,int pos)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    struct node *temp=NULL;
    temp=head;
    if(pos==1)
    {
        new->link=head->link;
    }
    while(temp!=head->link)
    {
        temp=temp->link;
        pos--;
    }
    new->link=temp->link;
    temp->link=new;
    if(temp==head)
    {
        head=head->link;
    }
    return head;
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=head;
    
    printf("\ninser at begin\n");
    head=insert_begin(head,20);
    traverse(head);
    
    printf("\ninsert at last\n");
    head=insert_last(head,30);
    traverse(head);
    
    printf("\ninsert at random\n");
    head=insert_random(head,40,3);
    traverse(head);
}