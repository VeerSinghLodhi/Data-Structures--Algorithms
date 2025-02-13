#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    char name[20];
    struct Person *next;
}*top;
void add()
{
    struct Person *ptr;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else {
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        if(top==NULL)
        {
            top=ptr;
            ptr->next=NULL;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
        printf("\nNew Person Added!!");
    }
}
void traverse()
{
    if(top==NULL)
        printf("\nNo Person found!!");
    else{
        struct Person *ptr;
        for(ptr=top;(ptr);ptr=ptr->next)
        {
            printf("\nSerial no. %d",ptr->srno);
            printf("\nName is %s",ptr->name);
            printf("\n---------------------");
        }
    }
}
void del()
{
    if(top==NULL)
        printf("\nNo Person found!!");
    else{
        struct Person *prev;
        prev=top;
        top=top->next;
        free(prev);
        printf("\nDeleted!!");
    }
}
void main()
{
    top=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            del();
    }while(c!=4);
}
