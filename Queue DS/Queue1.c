#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
}*front,*rear;
void enqueue()
{
    struct Queue *ptr;
    ptr=(struct Queue*)malloc(sizeof(struct Queue));
    if(ptr==NULL)
        printf("Cannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(front==NULL)
        {
            front=rear=ptr;
        }
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
    if(front==NULL)
        printf("\nNo nodes found!!");
    else{
        struct Queue *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
        }
    }
}
void dequeue()
{
    if(front==NULL)
        printf("\nNo nodes found!!");
    else{
        struct Queue *prev;
        prev=front;
        front=front->next;
        free(prev);
        printf("\nDeleted!!");
    }
}
void main()
{
    front=rear=NULL;
    int c;
    do{
        printf("\n1. Add new node");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            enqueue();
        else if(c==2)
            traverse();
        else if(c==3)
            dequeue();
    }while(c!=4);
}
