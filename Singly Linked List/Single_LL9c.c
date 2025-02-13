#include<stdio.h>
struct Student
{
    int rollno;
    char name[20];
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr,*temp,*last;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory");
    else{
        printf("\nEnter Student Roll no : ");
        scanf("%d",&ptr->rollno);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
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
        printf("\nNew Student Added\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nRoll no %d",ptr->rollno);
            printf("\nName is %s",ptr->name);
            printf("\n------------------------");
        }
    }
}
void del(){
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        int no;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&no);
        struct Student *ptr,*prev;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->rollno==no)
            {
                if(ptr==head)
                {
                    head=head->next;
                }
                else if(ptr->next==NULL)
                {
                    prev->next=NULL;
                }
                else{
                    prev->next=ptr->next;
                }
            }
            prev=ptr;
        }
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete ");
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
