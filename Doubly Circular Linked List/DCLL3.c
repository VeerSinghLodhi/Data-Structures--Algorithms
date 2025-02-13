#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int data;
    struct Student *prev,*next;
}*head,*end;

void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL)
        {
            head=end=ptr;
            ptr->prev=head;
            ptr->next=head;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            end=ptr;
            head->prev=end;
            end->next=head;
        }
        printf("\nAdded!!");
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
            printf("\nData is %d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void rTraverse()
{
    if(head==NULL){
        printf("\nNo Student Found!!");
        return;
    }
    struct Student *ptr;
    ptr=end;
    do{
        printf("\nData is %d",ptr->data);
        ptr=ptr->prev;
    }while(ptr!=end);
}
void del()
{
    if(head==NULL)
        printf("\nNO Student Found!!");
    else{
        int c,ans=0;
        struct Student *ptr;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&c);
        ptr=head;
        do{
            if(ptr->data==c)
            {
                if(ptr==head)
                {
                    if(ptr->next==head)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=end;
                        end->next=head;
                    }
                }
                else if(ptr==end)
                {
                    end=end->prev;
                    end->next=head;
                    head->prev=end;
                }
                else
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                free(ptr);
                printf("\nDeleted!!");
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nRoll no is not found!!\n");
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add a Student");
        printf("\n2. Traverse ");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            rTraverse();
        else if(c==4)
            del();
    }while(c!=5);
}
