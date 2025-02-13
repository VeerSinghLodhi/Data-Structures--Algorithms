#include<stdio.h>
#include<stdlib.h>
struct Student{
    int data;
    struct Student *prev,*next;
}*head,*end;
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL)
        {
            head=end=ptr;
            ptr->prev=ptr->next=NULL;
        }
        else{
            int c;
            printf("\nWhere do you want to insert?\n");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                head->prev=ptr;
                ptr->next=head;
                head=ptr;
                head->prev=NULL;
            }
            else if(c==2)
            {
                int v,ans=0;
                printf("\nEnter Data after which you want insert new record : ");
                scanf("%d",&v);
                struct Student *temp;
                temp=head;
                do{
                    if(temp->data==v)
                    {
                        ptr->next=temp->next;
                        ptr->prev=temp;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=NULL);
                if(ans==0)
                    printf("\nData is not found!!");
            }
            else if(c==3)
            {
                end->next=ptr;
                ptr->prev=end;
                end=ptr;
                end->next=NULL;
            }
        }
        printf("\nNew Student Added");
    }
}
void traverseHeadToEnd()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Student *temp;
        temp=head;
        do{
            printf("\nData is %d",temp->data);
            printf("\n---------------------");
            temp=temp->next;
        }while(temp!=NULL);
    }
}
void traverseEndToHead()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Student *temp;
        temp=end;
        do{
            printf("\nData is %d",temp->data);
            printf("\n---------------------");
            temp=temp->prev;
        }while(temp!=NULL);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Student *temp;
        int c,ans=0;
        printf("\nEnter Data to delete : ");
        scanf("%d",&c);
        temp=head;
        do{
            if(temp->data==c)
            {
                if(temp==head)
                {
                    if(head->next==NULL)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=NULL;
                    }
                }
                else if(temp==end)
                {
                    end=end->prev;
                    end->next=NULL;
                }
                else{
                    temp->next->prev=temp->prev;
                    temp->prev->next=temp->next;
                }
                ans=1;
                free(temp);
                printf("\nDeleted!!");
                break;
            }
            temp=temp->next;
        }while(temp!=NULL);
        if(ans==0)
            printf("\nData is not found!!");
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Student ");
        printf("\n2. Traverse (Head to End)");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverseHeadToEnd();
        else if(c==3)
            traverseEndToHead();
        else if(c==4)
            del();
    }while(c!=5);
}
