
#include<stdio.h>
struct Person
{
    int srno;
    char name[20];
    struct Person *next;
}*head;
struct Person *createNode()
{
    struct Person *p;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        return NULL;
    else {
        printf("\nEnter Serial number : ");
        scanf("%d",&p->srno);
        printf("\nEnter Name : ");
        scanf("%s",&p->name);
        return p;
    }
}
void addBeg()
{
    if(head==NULL)
        printf("\nNo node found");
    else
    {
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else
        {
            ptr->next=head;
            head=ptr;
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nNo node found!");
    else
    {
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else
        {
            int i;
            struct Person *temp;
            printf("\nEnter Serial number which after you want to add a new node : ");
            scanf("%d",&i);
            for(temp=head;(temp);temp=temp->next)
            {
                if(temp->srno==i)
                {
                    ptr->next=temp->next;
                    temp->next=ptr;
                }
            }
        }
    }
}
void addEnd()
{
    struct Person *ptr,*temp,*prev;
    ptr=createNode();
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
    }
    else
    {
        for(temp=head;(temp);temp=temp->next)
        {
            prev=temp;
        }
        prev->next=ptr;
        ptr->next=NULL;
    }
}
void display()
{
    struct Person *ptr;
    for(ptr=head;(ptr);ptr=ptr->next)
    {
        printf("\nSerial number %d",ptr->srno);
        printf("\nName is %s",ptr->name);
        printf("\n----------------------------");
    }
}
void main()
{
    int c;
    do{
        printf("\n1. add new node at the beg.");
        printf("\n2. add new node at the middle");
        printf("\n3. add new node at the end");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMid();
        else if(c==3)
            addEnd();
        else if(c==4)
            display();
    }while(c!=5);
}
