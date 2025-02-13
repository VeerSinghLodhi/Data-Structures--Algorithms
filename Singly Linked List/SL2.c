#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int srno;
    char name[30];
    char gender;
    struct Student *next;
}*head;
void addNode()
{
    struct Student *ptr,*temp,*last;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        fflush(stdin);
        printf("\nEnter Gender : ");
        scanf("%c",&ptr->gender);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else{
            for(temp=head;(temp);temp=temp->next)
            {
                last=temp;
            }
            last->next=ptr;
            ptr->next=NULL;
        }
        printf("\nNew Student Added");
    }
}
void show()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        struct Student *temp;
        for(temp=head;(temp);temp=temp->next)
        {
            printf("\nSerial number is %d",temp->srno);
            printf("\nName is %s",temp->name);
            printf("\nGender is %c",temp->gender);
            printf("\n-------------------------");
        }
    }
}
void del()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        int c,ans=0;
        struct Student *ptr,*prev;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&c);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->srno==c)
            {
                if(ptr==head)
                {
                    head=head->next;
                }
                else if (ptr->next==NULL)
                {
                    prev->next=NULL;
                }
                else{
                    prev->next=ptr->next;
                }
                ans=1;
                free(ptr);
                printf("\nStudent Deleted!!");
                break;
            }
            prev=ptr;
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
        printf("\n1. Add new Student");
        printf("\n2. Show");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\n5. Select a choice : ");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            show();
        else if(c==3)
            del();
    }while(c!=4);
}
