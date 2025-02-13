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
        rear->next=NULL;
        printf("\nNew Data Added");
    }
}
void display()
{
    if(front==NULL)
        printf("\nQueue is empty!!");
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
        printf("\nQueue is empty!!");
    else{
        struct Queue *temp;
        temp=front;
        front=front->next;
        free(temp);
        printf("\nDeleted!!");
    }
}
void main()
{
    front=rear=NULL;
    int c;
    do{
        printf("\n1. Enqueue");
        printf("\n2. Display");
        printf("\n3. Dequeue");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            enqueue();
        else if(c==2)
            display();
        else if(c==3)
            dequeue();
    }while(c!=4);
}
