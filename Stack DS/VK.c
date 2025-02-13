#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int qdata;
    struct Queue *next;
}*front,*rear;
struct Stack
{
    int sdata;
    struct Stack *next;
}*top;
void add()
{
    struct Queue *ptr;
    ptr=(struct Queue*)malloc(sizeof(struct Queue));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter data : ");
        scanf("%d",&ptr->qdata);
        if(front==NULL)
            front=rear=ptr;
        else{
            rear->next=ptr;
            rear=ptr;
        }
        ptr->next=NULL;
        printf("\nAdded!!");
    }
}
void traverse()
{
    struct Queue *temp;
    for(temp=front;(temp);temp=temp->next)
    {
        printf("\nData %d",temp->qdata);
    }
}
void reverse()
{
    top=NULL;
    struct Queue *temp,*prev;
    temp=front;
    while(temp)
    {
        struct Stack *ptr;
        ptr=(struct Stack*)malloc(sizeof(struct Stack));
        ptr->sdata=temp->qdata;
        if(top==NULL)
        {
            top=ptr;
            ptr->next=NULL;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
        prev=temp;
        temp=temp->next;
        free(prev);
    }
    front=rear=NULL;
    struct Stack *p,*s;
    p=top;
    while((p))
    {
        struct Queue *ptr;
        ptr=(struct Queue*)malloc(sizeof(struct Queue));
        ptr->qdata=p->sdata;
        if(front==NULL)
        {
            front=rear=ptr;
        }
        else{
            rear->next=ptr;
            rear=ptr;
        }
        ptr->next=NULL;
        s=p;
        p=p->next;
        free(s);
    }
    printf("\nReversed!!");
}
void main()
{
    front=rear=NULL;
    top=NULL;
    int c;
    do{
        printf("\n1. Add");
        printf("\n2. Traverse");
        printf("\n3. Reverse");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            reverse();
    }while(c!=4);
}
