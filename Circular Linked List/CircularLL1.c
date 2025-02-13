#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    struct Person *next;
}*head;
void add()
{
    struct Person *ptr,*temp;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->srno);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
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
        printf("\nNo Nodes Found!!\n");
    else{
        struct Person *ptr;
        ptr=head;
        do{
            printf("\nData is %d",ptr->srno);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse");
        printf("\n3. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
    }while(c!=3);
}
