#include<stdio.h>
#include<stdlib.h>
struct Person{
    int data;
    struct Person *next;
}*head;
void add()
{
    struct Person *ptr,*temp,*prev;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL)
        {
            head=ptr;
            head->next=head;
        }
        else{
            temp=head;
            while(temp->next!=head)
                temp=temp->next;

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
        struct Person *temp;
        temp=head;
        do{
            printf("\nData is %d",temp->data);
            printf("\n---------------------");
            temp=temp->next;
        }while(temp!=head);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *temp,*prev,*v;
        int c,ans=0;
        printf("\nEnter Data to delete : ");
        scanf("%d",&c);
        temp=head;
        do{
            if(temp->data==c)
            {
                if(temp==head)
                {
                    if(head->next==head)
                        head=NULL;
                    else{
                        v=head;
                        while(v->next!=head)
                            v=v->next;
                        head=head->next;
                        v->next=head;
                    }
                }
                else if(temp->next==head)
                {
                    prev->next=head;
                }
                else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=head);
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
            del();
    }while(c!=4);
}
