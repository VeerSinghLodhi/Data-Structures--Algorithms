#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int srno;
    char name[20];
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr,*temp,*last;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Student Roll no. : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else{
            for(temp=head;temp!=NULL;temp=temp->next)
                last=temp;
            last->next=ptr;
            ptr->next=NULL;
        }
        printf("\nNew Student Added");
    }
}
void show()
{
    if(head==NULL)
        printf("\nLink List is Empty!!");
    else{
        struct Student *ptr;
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            printf("\nRoll no %d",ptr->srno);
            printf("\nName is %s",ptr->name);
            printf("\n-----------------------------");
        }
    }
}
void del()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        struct Student *ptr,*temp;
        int c,ans=0;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&c);
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            if(c==ptr->srno)
            {
                if(head==ptr)
                {
                    head=head->next;
                }
                else if(ptr->next==NULL)
                {
                    temp->next=NULL;
                }
                ans=1;
                free(ptr);
                printf("\nStudent Deleted");
                break;
            }
            temp=ptr;
        }
        if(ans==0)
            printf("Student Roll No is not found!!");
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n-------------Link List--------------");
        printf("\n1. Add new Student");
        printf("\n2. Show All Student");
        printf("\n3. Delete Student");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            show();
        else if(c==3)
            del();
    }while(c!=4);
}
