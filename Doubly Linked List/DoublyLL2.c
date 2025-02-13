#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int srno;
    char name[20];
    struct Person *prev,*next;
}*head,*end;

void add()
{
    struct Person *ptr;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            head->prev=NULL;
            head->next=NULL;
        }
        else {
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
        printf("\nNo Person found!!");
    else{
        struct Person *ptr;
        ptr=head;
        while((ptr)){
            printf("\nSerial no. %d",ptr->srno);
            printf("\nName %s",ptr->name);
            ptr=ptr->next;
            printf("\n----------------------");
        }
    }
}

void rTraverse()
{
    if(head==NULL)
        printf("\nNo Person found!");
    else{
        struct Person *ptr;
        for(ptr=end;ptr!=NULL;ptr=ptr->prev)
        {
            printf("\nSerial no. %d",ptr->srno);
            printf("\nName %s",ptr->name);
            printf("\n----------------------");
        }
    }
}
void deleteElement(){
    if(head==NULL)
        printf("\nNo Person found!!\n");
    else{
        struct Person *ptr;
        int sr,ans=0;
        printf("\nEnter Serial number to delete : ");
        scanf("%d",&sr);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->srno==sr)
            {
                if(ptr==head)
                {
                    head=head->next;
                    head->prev=NULL;
                }
                else if(ptr==end)
                {
                    end=ptr->prev;
                    end->next=NULL;
                    //ptr->prev=NULL;
                }
                else {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                free(ptr);
                printf("\nPerson Deleted!!\n");
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nSerial number not found!!\n");

    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse(Head to End)");
        printf("\n3. Traverse(End to Head)");
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
