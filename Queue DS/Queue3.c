#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
}*front,*rear,*top;
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
        ptr->next=NULL;
    }
}
void dequeue()
{

}
void veersingh(struct Queue *veer)
{
    if(veer==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Queue *ptr;
        for(ptr=veer;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
        }
    }
}
void traverse()
{
    veersingh(front);
}
void copyStack()
{
    struct Queue *temp,*ptr;
    for(temp=front;(temp);temp=temp->next)
    {
        ptr=(struct Queue*)malloc(sizeof(struct Queue));
        ptr->data=temp->data;
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
}
void straverse()
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
void main()
{
    front=rear=NULL;
    top=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Copy Stack");
        printf("\n5. Traverse Copy Stack");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            enqueue();
        else if(c==2)
            traverse();
        else if(c==3)
            dequeue();
        else if(c==4)
            copyStack();
        else if(c==5)
            straverse();
    }while(c!=6);
}

