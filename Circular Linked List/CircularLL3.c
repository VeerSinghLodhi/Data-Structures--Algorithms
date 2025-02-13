#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int data;
    struct Person *next;
}*head;
struct Person *createNode()
{
    struct Person *p;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        return NULL;
    else{
        printf("\nEnter Data : ");
        scanf("%d",&p->data);
        return p;
    }
}
void addBeg()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *ptr,*temp;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else{
            temp=head;
            while(temp->next!=head)
                temp=temp->next;

            ptr->next=head;
            head=ptr;
            temp->next=head;
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *ptr,*temp;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else{
            int c,ans=0;
            printf("\nEnter data after which you want to insert new record : ");
            scanf("%d",&c);
            temp=head;
            do{
                if(temp->data==c)
                {
                    ptr->next=temp->next;
                    temp->next=ptr;
                    printf("\nNew Person Added!!");
                    ans=1;
                    break;
                }
                temp=temp->next;
            }while(temp!=head);
            if(ans==0)
                printf("\nData is not found!!");
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
            ptr->next=head;
        }
        else{
            struct Person *temp;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
        }
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *ptr;
        ptr=head;
        do{
            printf("\nData %d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add at the Beginning");
        printf("\n2. Add at the Specific Position");
        printf("\n3. Add at the End");
        printf("\n4. Traverse");
        printf("\n5. Exit");
        printf("\nSelect your Choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMid();
        else if(c==3)
            addEnd();
        else if(c==4)
            traverse();
    }while(c!=5);
}
