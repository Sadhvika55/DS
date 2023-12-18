/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front=-1;
int rear=-1;
int isempty()
{
    return rear==-1;
}
int isfull()
{
    return front==MAX_SIZE-1;
}
int front_value()
{
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        return queue[front];
    }
}
int enqueue(int value)
{
    if(isfull())
    {
        printf("stack is full");
    }
    else
    {
        return queue[++rear]=value;
    }
}
int dequeue()
{
    if(isempty())
    {
        printf("stack is empty");
    }
    else
    {
        if(front==rear)
        {
            front=-1;
        }
        else
        {
            front++;
        }
    }
    return queue[rear-1];
}
int display()
{
    int i;
    if(isempty())
    {
        printf("stack is empty\n");
    }
    for(i=front;i<rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}

int main()
{
   /*** 
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("after enqueue operation\n");
    display();
    printf("front_value=%d",front_value());
    dequeue();
    dequeue();
    printf("\nafter dequeue operation\n");
    display();
***/
    int choice,value;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the top element\n");
        printf("4.Display all stack elements\n");
        printf("5.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    printf("\nEnter the item to be pushed : ");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2:
                    value = dequeue();
                    printf("\ndequeue value is : %d\n",value );
                    break;
            case 3:
                    printf("\nvalue at the top is : %d\n", front_value() );
                    break;
            case 4:
                    display();
                    break;
            case 5:
                    exit(0);
            default:
                    printf("\nWrong choice\n");
        }
    }

    return 0;



}









