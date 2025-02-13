#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    struct Person *next;
}*head;
void add()
{
    struct Person *ptr,*prev,*temp;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        if(head==NULL)
        {
            head=ptr;
        }
        else{
            for(temp=head;(temp);temp=temp->next)
                prev=temp;
            prev->next=ptr;
        }
        ptr->next=NULL;
        printf("\nNew Person Added!!");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *temp;
        for(temp=head;(temp);temp=temp->next)
        {
            printf("\nData is %d",temp->srno);
            printf("\n-----------------------");
        }
    }
}
void delPerson()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *temp,*prev;
        int c,ans=0;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&c);
        for(temp=head;(temp);temp=temp->next)
        {
            if(temp->srno==c)
            {
                if(temp==head)
                {
                    head=head->next;
                }
                else if(temp->next==NULL)
                {
                    prev->next=NULL;
                }
                else{
                    prev->next=temp->next;
                }
                free(temp);
                ans=1;
                printf("\nDeleted!!");
                break;
            }
            prev=temp;
        }
        if(ans==0)
            printf("\nSerial number is not found!!");
    }
}
void main()
{
    head=NULL;
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
            delPerson();
    }while(c!=4);
}
