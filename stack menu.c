/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int stack[MAX_SIZE];
int top=-1;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==MAX_SIZE-1;
}
int peek()
{
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        return stack[top];
    }
}
int push(int value)
{
    if(isfull())
    {
        printf("stack is full");
    }
    else
    {
        return stack[++top]=value;
    }
}
int pop()
{
    if(isempty())
    {
        printf("stack is empty");
    }
    else
    {
        return stack[top--];
    }
}
int display()
{
    int i;
    if(isempty())
    {
        printf("stack is empty\n");
    }
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
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
                    push(value);
                    break;
            case 2:
                    value = pop();
                    printf("\nPopped item is : %d\n",value );
                    break;
            case 3:
                    printf("\nItem at the top is : %d\n", peek() );
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









