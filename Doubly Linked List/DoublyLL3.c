#include<stdio.h>
#include<stdlib.h>
struct Person{
    int srno;
    struct Person *next,*prev;
}*head,*end;

struct Person *createNode()
{
    struct Person *p;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        return NULL;
    else{
        printf("\nEnter Serial no. : ");
        scanf("%d",&p->srno);
        return p;
    }
}
void addBeg()
{
    if(head==NULL)
        printf("\nNo Nodes found!!\n");
    else{
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCannot allocate memory!!");
        else{
            head->prev=ptr;
            ptr->next=head;
            head=ptr;
            head->prev=NULL;
            printf("\nNew Person Added\n");
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nNo Nodes found!!\n");
    else{
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else{
            struct Person *temp;
            int no,ans=0;
            printf("\nEnter Serial no after which you want add a new Person : ");
            scanf("%d",&no);
            for(temp=head;(temp);temp=temp->next)
            {
                if(temp->srno==no)
                {
                    ptr->prev=temp;
                    ptr->next=temp->next;
                    temp->next->prev=ptr;
                    temp->next=ptr;
                    printf("\nNew Person Added\n");
                    ans=1;
                    break;
                }
            }
            if(ans==0)
                printf("\nSerial number is not found!!\n");
        }
    }
}
void addEnd()
{
    struct Person *ptr;
    ptr=createNode();
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            ptr->prev=NULL;
            ptr->next=NULL;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            ptr->next=NULL;
            end=ptr;
        }
        printf("\nNew Person Added!!\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes found!!\n");
    else{
        struct Person *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nSerial no %d",ptr->srno);
            printf("\n-----------------------");
        }
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Nodes found!!\n");
    else{
        struct Person *ptr;
        for(ptr=end;(ptr);ptr=ptr->prev)
        {
            printf("\nSerial no %d",ptr->srno);
            printf("\n-----------------------");
        }
    }
}
void deleteElement()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Person *ptr;
        int srn,ans=0;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&srn);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->srno==srn)
            {
                if(ptr==head)
                {
                    head=head->next;
                    head->prev=NULL;
                }
                else if(ptr==end)
                {
                    end=end->prev;
                    end->next=NULL;
                }
                else{
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                printf("\nPerson Deleted!!\n");
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nSerial number is not found!!");
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new node at the beg.");
        printf("\n2. Add new node at the specific position");
        printf("\n3. Add new node at end");
        printf("\n4. Traverse(Head to End)");
        printf("\n5. Traverse(End to Head)");
        printf("\n6. Delete");
        printf("\n7. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMid();
        else if(c==3)
            addEnd();
        else if(c==4)
            traverse();
        else if(c==5)
            rTraverse();
        else if(c==6)
            deleteElement();
    }while(c!=7);
}
