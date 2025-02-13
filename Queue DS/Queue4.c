#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno,age;
    char name[20],grade;
    struct Student *next;
}*front,*rear;
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
        while(ptr->rollno<=0)
        {
            printf("\nInvalid roll no");
            printf("\nEnter valid roll no : ");
            scanf("%d",&ptr->rollno);
        }
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid age");
            printf("\nEnter valid age : ");
            scanf("%d",&ptr->age);
        }
        fflush(stdin);
        printf("\nEnter Grade : ");
        scanf("%c",&ptr->grade);
        if(front==NULL)
        {
            front=rear=ptr;
        }
        else{
            rear->next=ptr;
            rear=ptr;
        }
        ptr->next=NULL;
        printf("\nNew Student Added!");
    }
}
void traverse()
{
    if(front==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *temp;
        printf("\nStudent Details age : ");
        for(temp=front;(temp);temp=temp->next)
        {
            printf("\nRoll no %d",temp->rollno);
            printf("\nName is %s",temp->name);
            printf("\nAge is  %d",temp->age);
            printf("\nGrade is %c",temp->grade);
            printf("\n--------------------------");
        }
    }
}
void del()
{
    if(front==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *prev;
        prev=front;
        front=front->next;
        free(prev);
        printf("\nDeleted!");
    }
}
void main()
{
    front=rear=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
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
