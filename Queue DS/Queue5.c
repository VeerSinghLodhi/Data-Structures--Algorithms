#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    struct Student *next;
}*front,*rear,*top;
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
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
    if(front==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {
            printf("\nRoll no %d",ptr->rollno);
            printf("\n-----------------");
        }
    }
}
void del()
{
    if(front==NULL)
        printf("\nNo Student found!!");
    else{
        struct Student *prev;
        prev=front;
        front=front->next;
        free(prev);
        printf("\nDeleted!!");
    }
}
void copyStack()
{
    if(front==NULL)
        printf("\nCan not copy because Queue is Underflow!!");
    else{
        struct Student *ptr;
        for(ptr=front;(ptr);ptr=ptr->next)
        {

            struct Student *s;
            s=(struct Student*)malloc(sizeof(struct Student));
            s->rollno=ptr->rollno;
            if(top==NULL)
            {
                top=s;
                top->next=NULL;
            }
            else{
                s->next=top;
                top=s;
            }
        }
        printf("\nCopied");
    }
}
void stackTraverse()
{
    if(top==NULL)
        printf("\nStack is Underflow!!");
    else{
        struct Student *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
        {
            printf("\nRoll no is %d",ptr->rollno);
            printf("\n-------------");
        }
    }
}

void main()
{
    front=rear=top=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Copy Stack");
        printf("\n5. Stack Traverse");
        printf("\n6. Exit");
        printf("\nSelect choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            del();
        else if(c==4)
            copyStack();
        else if(c==5)
            stackTraverse();
    }while(c!=6);
}
