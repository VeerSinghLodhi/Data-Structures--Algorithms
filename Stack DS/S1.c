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
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(top==NULL)
        {
            top=ptr;
            top->next=NULL;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
    }
}
void display()
{
    if(top==NULL)
        printf("\nStack is empty!!");
    else{
        struct Stack *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
            printf("\nData is %d",ptr->data);
    }
}
void pop()
{
    if(top==NULL)
        printf("\nStack is empty!!");
    else{
        struct Stack *temp;
        temp=top;
        top=top->next;
        free(temp);
        printf("\nDeleted");
    }
}
void main()
{
    top=NULL;
    int c;
    do{
        printf("\n1. Push");
        printf("\n2. Display");
        printf("\n3. Pop");
        printf("\n4. Exit");
        printf("\nSelect a choice :");
        scanf("%d",&c);
        if(c==1)
            push();
        else if(c==2)
            display();
        else if(c==3)
            pop();
    }while(c!=4);
}
