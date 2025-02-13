#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    struct Student *prev,*next;
}*head,*end;
struct Student *createNode()
{
    struct Student *s;
    s=(struct Student*)malloc(sizeof(struct Student));
    if(s==NULL)
        return NULL;
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&s->rollno);
        return s;
    }
}
void addBeg()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCannot allocate memory!!");
        else{
            ptr->next=head;
            head->prev=ptr;
            ptr->prev=end;
            head=ptr;
            end->next=head;
            printf("\nStudent Added!!");
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr,*temp;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCannot allocate memory!!");
        else{
            int c,ans=0;
            printf("\nEnter Roll no after which you want insert new record : ");
            scanf("%d",&c);
            temp=head;
            do{
                if(temp->rollno==c)
                {
                    ptr->prev=temp;
                    ptr->next=temp->next;
                    temp->next->prev=ptr;
                    temp->next=ptr;
                    ans=1;
                    printf("\nStudent Added!!");
                }
                temp=temp->next;
            }while(temp!=head);
            if(ans==0)
                printf("\nRoll no is not found!!");
        }
    }
}
void addEnd()
{
    struct Student *ptr;
    ptr=createNode();
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        if(head==NULL)
        {
            head=end=ptr;
            ptr->next=head;
            ptr->prev=end;
        }
        else{
            ptr->prev=end;
            end->next=ptr;
            end=ptr;
            ptr->next=head;
            head->prev=end;
        }
        printf("\nStudent Added!!");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nRoll no %d",ptr->rollno);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr;
        ptr=end;
        do{
            printf("\nRoll no %d",ptr->rollno);
            ptr=ptr->prev;
        }while(ptr!=end);
    }
}
void main()
{
    int c;
    head=end=NULL;
    do{
        printf("\n1. Add at the Beginning");
        printf("\n2. Add at the Specific Position");
        printf("\n3. Add at the End");
        printf("\n4. Traverse (Head to End)");
        printf("\n5. Traverse (End to Head)");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMid();
        else if(c==3)
            addEnd();
        else if(c==4)
            traverse();
        else if(c==5)
            rTraverse();
    }while(c!=6);
}
