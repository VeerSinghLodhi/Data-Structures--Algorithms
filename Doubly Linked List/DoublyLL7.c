#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    struct Person *prev,*next;
}*head,*end;
void add()
{
    struct Person *ptr;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter roll no : ");
        scanf("%d",&ptr->srno);
        if(head==NULL)
        {
            head=end=ptr;
            ptr->prev=ptr->next=NULL;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            end=ptr;
            ptr->next=NULL;
        }
        printf("\nNew Person Added!!");
    }
}
void traverseHeadToEnd()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *temp;
        temp=head;
        do{
            printf("\nData is %d",temp->srno);
            printf("\n-------------------");
            temp=temp->next;
        }while(temp!=NULL);
    }
}
void traverseEndToHead()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *temp;
        temp=end;
        do{
            printf("\nData is %d",temp->srno);
            printf("\n-------------------------");
            temp=temp->prev;
        }while(temp!=NULL);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *temp;
        int c,ans=0;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&c);
        temp=head;
        do{
            if(temp->srno==c)
            {
                if(temp==head)
                {
                    if(head->next==NULL)
                        head=NULL;
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
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
                ans=1;
                free(temp);
                printf("\nDeleted!!");
                break;
            }
            temp=temp->next;
        }while(temp!=NULL);
        if(ans==0)
            printf("\nSerial number is not found!!");
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse (Head to End)");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
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
