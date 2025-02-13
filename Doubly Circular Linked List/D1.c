#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    char name[30];
    struct Person *prev,*next;
}*head,*end;
void addNode()
{
    struct Person *ptr;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL)
        {
            head=end=ptr;
            head->prev=NULL;
            end->next=NULL;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            end=ptr;
            end->next=NULL;
        }
    }
}
void traverseHeadToEnd()
{
    if(head==NULL)
        printf("\nLink list is empty!!");
    else{
        struct Person *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nSerial number %d",ptr->srno);
            printf("\nName is %s",ptr->name);
            printf("\n--------------------");
        }
    }
}
void traverseEndToHead()
{
    if(head==NULL)
        printf("\nLink list is empty!!");
    else
    {
        struct Person *ptr;
        for(ptr=end;(ptr);ptr=ptr->prev)
        {
            printf("\nSerial number %d",ptr->srno);
            printf("\nName is %s",ptr->name);
            printf("\n-------------------------");
        }
    }
}
void del()
{
    if(head==NULL)
        printf("\nLink list is empty!!");
    else{
        int c;
        struct Person *ptr;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&c);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->data==c)
            {
                if(ptr->prev==NULL){
                    head=head->next;
                    head->prev=NULL;
                }
                else if(ptr==end){

                }
                else{

                }
            }
        }
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse(head to end)");
        printf("\n3. Traverse(end to head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            traverseHeadToEnd();
        else if(c==3)
            traverseEndToHead();
        else if(c==4)
            del();
    }while(c!=5);
}
