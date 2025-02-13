#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[20];
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr,*temp;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Student Rollno : ");
        scanf("%d",&ptr->rollno);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
            int c;
            printf("\nWhere do you want to insert ?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                ptr->next=head;
                head=ptr;
                temp->next=head;
            }
            else if(c==2)
            {
                int no,ans=0;
                printf("\nEnter Roll no after which you want to insert new record : ");
                scanf("%d",&no);
                temp=head;
                do{
                    if(temp->rollno==no)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0)
                    printf("\nRoll no is not found!!");
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
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nRoll no %d",ptr->rollno);
            printf("\nName is %s",ptr->name);
            printf("\n-----------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        int no,ans=0;
        struct Student *ptr,*temp,*prev;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&no);
        ptr=head;
        do{
            if(ptr->rollno==no)
            {
                if(ptr->next==head)
                {
                    if(ptr==head)
                        head=NULL;
                    else{
                        prev->next=head;
                    }
                }
                else if(head==ptr)
                {
                    temp=head;
                    while(temp->next!=head)
                        temp=temp->next;
                    head=head->next;
                    temp->next=head;
                }
                else{
                    prev->next=ptr->next;
                }
                ans=1;
                printf("\nStudent Deleted!!");
                break;
            }
            prev=ptr;
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nRoll no is not found!!");
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
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
