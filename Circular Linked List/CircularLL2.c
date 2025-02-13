#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id,age;
    char name[20],grade;
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Student ID : ");
        scanf("%d",&ptr->id);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        fflush(stdin);
        printf("\nEnter Student Grade : ");
        scanf("%c",&ptr->grade);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
            struct Student *temp;
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;f
            }
            temp->next=ptr;
            ptr->next=head;
        }
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do
        {
            printf("\nStudent ID is %d",ptr->id);
            printf("\nStudent Name is %s",ptr->name);
            printf("\nStudent Age is %d",ptr->age);
            printf("\nStudent Grade is %c",ptr->grade);
            printf("\n--------------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Exit");
        printf("\nSelect your Choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
    }while(c!=3);
}
