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
struct node* del_begin(struct node *head)
{
    struct node *temp=head->link;
    head->link=temp->link;
    free(temp);
    temp=NULL;
    return head;
}
struct node* del_last(struct node *head)
{
    struct node *temp=head->link;
    while(temp->link!=head)
    {
        temp=temp->link;
    }
    struct node *new=head->link;
    head->link=temp->link;
    free(new);
    new=NULL;
    temp->link=head->link;
    return head;
}
struct node* del_random(struct node *head,int pos)
{
    struct node *temp=head->link;
    struct node *new=head->link;
    if(head==NULL)
    {
        printf("empty\n");
    }
    while(pos!=1)
    {
        new=head;
        temp=temp->link;
        pos--;
    }
    new->link=temp->link;
    free(temp);
    return head;
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=head;
    
    head=insert_begin(head,20);
    traverse(head);
    
    printf("\ndelet at begin\n");
    head=del_begin(head);
    traverse(head);
    
    head=insert_begin(head,30);
    traverse(head);
    
    printf("\n delet at last\n");
    head=del_last(head);
    traverse(head);
    printf("\nafter inserting\n");
    head=insert_begin(head,40);
    traverse(head);
    printf("\nafter inserting\n");
    head=insert_begin(head,50);
    traverse(head);
    printf("\ndelet at random\n");
    head=del_random(head,2);
    traverse(head);
}