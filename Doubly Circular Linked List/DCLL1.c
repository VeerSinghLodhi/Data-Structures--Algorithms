#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int data;
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
        scanf("%d",&ptr->data);
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            head->next=head;
            ptr->prev=NULL;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            end=ptr;
            ptr->next=head;
        }
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *ptr;
        ptr=head;
        do{
            printf("\nData is %d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *ptr;
        ptr=end;
        do{
            printf("\nData is %d",ptr->data);
            ptr=ptr->prev;
        }while(ptr!=NULL);
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse(Head to End)");
        printf("\n3. Traverse(End to Head");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            rTraverse();
    }while(c!=4);
}
