#include<stdio.h>
#include<stdlib.h>
struct Student{
    int rollno;
    struct Student *next,*prev;
}*head,*end;

void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            ptr->next=NULL;
            end->prev=NULL;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            ptr->next=NULL;
            end=ptr;
        }
    }
}

void traverse()
{
    if(head==NULL)
        printf("\nNo Students found!!\n");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nRoll no %d",ptr->rollno);
            printf("\n----------------------");
        }
    }
}

void rTraverse()
{
    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr;
        ptr=end;
        while((ptr))
        {
            printf("\nRoll no %d",ptr->rollno);
            ptr=ptr->prev;
            printf("\n-----------------------");
        }
    }
}

void deleteElement()
{
    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr;
        int sid;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->rollno==sid)
            {
                if(ptr==head)
                {
                    head=head->next;
                    head->prev=NULL;
                }
                else if(ptr==end){
                    end=ptr->prev;
                    end->next=NULL;
                }
                else{
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
            }
        }
        printf("\nStudent Deleted");
    }
}

void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new student");
        printf("\n2. Traverse(Head-End)");
        printf("\n3. Traverse(End-Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            rTraverse();
        else if(c==4)
            deleteElement();
    }while(c!=5);
}
