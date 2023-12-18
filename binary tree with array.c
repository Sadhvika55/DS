/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#define MAX 7
char tree[MAX];
void root(char node)
{
    if(tree[0]!=0)
    {
        printf("root is allocated");
    }
    else
    {
        tree[0]=node;
    }
}
void left(char node , int parent)
{
    if(tree[parent]=='\0')
    {
        printf("parent doesnot exist\n");
    }
    else
    {
    tree[(2*parent)+1]=node;
    }
}
void right(char node,int parent)
{
    if(tree[parent]=='\0')
    {
        printf("parent doesnot exist\n");
    }
    else
    {
        tree[(2*parent)+2]=node;
    }
}
void display()
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(tree[i]=='\0')
        {
            printf("NULL");
        }
        printf("%c-",tree[i]);
    }
}
void main()
{
    root('A');
    left('B',0);
    right('C',0);
    left('D',1);
    right('E',1);
    right('F',2);
    printf("binary tree=\n");
    display();
}