#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int data;
    struct Stack *next;
}*top;
void push()
{
    struct Stack *ptr;
    ptr=(struct Stack*)malloc(sizeof(struct Stack));
    printf("\nEnter Data : ");
    scanf("%d",&ptr->data);
    if(top==NULL)
    {
        top=ptr;
        ptr->next=NULL;
    }
    else{
        ptr->next=top;
        top=ptr;

    }
}
void traverse()
{
    if(top==NULL)
        printf("\nNo nodes found!!");
    else{
        struct Stack *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
        }
    }
}
void pop()
{
    if(top==NULL)
        printf("\nNo nodes found!!");
    else{
        struct Stack *prev;
        prev=top;
        top=top->next;
        free(prev);
        printf("\nDeleted!\n");
    }
}
void main()
{
    top=NULL;
    int c;
    do{
        printf("\n1. Add new node");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            push();
        else if(c==2)
            traverse();
        else if(c==3)
            pop();
    }while(c!=4);
}
