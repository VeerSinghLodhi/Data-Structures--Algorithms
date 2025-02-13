#include<stdio.h>
#include<stdlib.h>
struct Person{
    int srno;
    char name[20];
    struct Person *next;
}*head;
void newPersonAdded()
{
    printf("\nNew Person Added!");
    printf("\n---------------------------");
}
struct Node *createNode()
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
void addBegin()
{
    if(head==NULL)
        printf("\nNo Node found!!\n---------------------------");
    else {
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else {
            ptr->next=head;//120-->80              //Ka kar rao re papiii;
            head=ptr;//head --->120;
            newPersonAdded();
        }
    }
}

void addMiddle()
{
    if(head==NULL)
        printf("\nNO Node found!!\n---------------------------");
    else{
        struct Person *ptr,*temp;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else
        {
            int i,ans=0;
            struct Person *temp;
            printf("\nEnter Serial number after which you want to add a new node : ");
            scanf("%d",&i);
            for(temp=head;(temp);temp=temp->next)
            {
                if(temp->srno==i)
                {
                    ptr->next=temp->next;
                    temp->next=ptr;
                    ans=1;
                    newPersonAdded();
                    break;
                }
            }
            if(ans==0)
            {
                printf("\nSerial number does not exist!!");
                printf("\n---------------------------");
            }
        }
    }
}

void addEnd()
{
        struct Person *ptr,*temp,*prev;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else{
            if(head==NULL)
            {
                head=ptr;
                ptr->next=NULL;
                newPersonAdded();
            }
            else{
                for(temp=head;(temp);temp=temp->next)
                {
                    prev=temp;
                }
                prev->next=ptr;
                ptr->next=NULL;
                newPersonAdded();
            }
        }
}

void show()
{
    struct Person *ptr;
    if(head==NULL)
    {
        printf("\nLinked list is empty!!");
        printf("\n---------------------------");
        return;
    }
    for(ptr=head;(ptr);ptr=ptr->next)
    {
        printf("\nSerial number is %d",ptr->srno);
        printf("\nName is %s",ptr->name);
        printf("\n------------------------------------");
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n--------------------Linked List Menu--------------------");
        printf("\n1. Add new node at the begin");
        printf("\n2. Add new node at the middle");
        printf("\n3. Add new node at the end");
        printf("\n4. Show");
        printf("\n5. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            addBegin();
        else if(c==2)
            addMiddle();
        else if(c==3)
            addEnd();
        else if(c==4)
            show();
    }while(c!=5);
}

