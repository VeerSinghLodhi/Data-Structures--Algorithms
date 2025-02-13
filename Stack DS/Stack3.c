#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int data;
    struct Student *next;
}*top,*front,*rear;
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    printf("\nEnter Data : ");
    scanf("%d",&ptr->data);
    if(top==NULL)
    {
        top=ptr;
        ptr->next=NULL;
    }
    else {
        ptr->next=top;
        top=ptr;
    }
    printf("\nNew Student Added!!");
}
void traverse()
{
    if(top==NULL)
        printf("\nNo Students Found!!");
    else{
        struct Student *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
            printf("\n------------------------");
        }
    }
}
void del()
{
    if(top==NULL)
        printf("\nNo Students Found!!");
    else{
        struct Student *prev;
        prev=top;
        top=top->next;
        free(prev);
        printf("\nDeleted!!");
    }
}
void copyQueue()
{
    if(top==NULL)
        printf("\nCannot Copy because Stack is underflow!!");
    else{
        struct Student *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
        {
            struct Student *q;
            q=(struct Student*)malloc(sizeof(struct Student));
            q->data=ptr->data;
            if(front==NULL)
                front=rear=q;
            else{
                rear->next=q;
                rear=q;
            }
            q->next=NULL;
        }
        printf("\nCopied!!");
    }
}
void QueueTraverse()
{
    if(front==NULL)
        printf("\nQueue is Underflow!!");
    else{
        struct Student *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
            printf("\n-------------------");
        }
    }
}
void main()
{
    top=front=rear=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Copy Queue");
        printf("\n5. Traverse Queue");
        printf("\n6. Exit");
        printf("Select a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            del();
        else if(c==4)
            copyQueue();
        else if(c==5)
            QueueTraverse();
    }while(c!=6);
}
