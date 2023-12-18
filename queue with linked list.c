 #include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL;
struct node *rear=NULL;
int isempty()
{
    return front==NULL;
}
int enqueue(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    if(front==NULL)
    {
        front=rear=new;
    }
    else
    {
    rear->link=new;
    rear=new;
    }
}
int dequeue()
{
    struct node *temp=NULL;
    temp=front;
    if(isempty())
    {
        printf("queue is empty\n");
    }
    front=temp->link;
    free(temp);
    return front->data;
}
int front_value()
{
    if(isempty())
    {
        printf("queue is empty\n");
    }
    else
    {
        return rear->data;
    }
}
int display()
{
    struct node *temp=NULL;
    temp=front;
    if(isempty())
    {
        printf("queue is empty\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("After enqueue\n");
    display();
    printf("front_value=%d\n",front_value());
    dequeue();
    dequeue();
    printf("After dequeue\n");
    display();
}
