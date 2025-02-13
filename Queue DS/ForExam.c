#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int data;
    struct Queue *next;
}*front,*rear;
void enqueue()
{
    struct Queue *ptr;
    ptr=(struct Queue*)malloc(sizeof(struct Queue));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter data :");
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
        printf("\nAdded");
    }
}
void show()
{
    if(front==NULL)
        printf("\nQueue is empty!!");
    else{
        struct Queue *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
            printf("\n--------------------");
        }
    }
}
void dequeue()
{
    if(front==NULL)
        printf("\nQueue is empty!!");
    else{
        struct Queue *ptr;
        ptr=front;
        front=front->next;
        free(ptr);
        printf("\nDeleted!!");
    }
}
void main()
{
    front=rear=NULL;
    int c;
    do{
        printf("\n-------------------Queue------");
        printf("\n1. Enqueue");
        printf("\n2. Show");
        printf("\n3. Dequeue");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            enqueue();
        else if(c==2)
            show();
        else if(c==3)
            dequeue();
    }while(c!=4);
}
