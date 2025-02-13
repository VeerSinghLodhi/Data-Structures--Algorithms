
#include<stdio.h>
struct Person
{
    int srno;
    char name[20];
    struct Person *next;
}*head;
struct Person *createNode()
{
    struct Person *p;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        return NULL;
    else {
        printf("\nEnter Serial number : ");
        scanf("%d",&p->srno);
        printf("\nEnter Name : ");
        scanf("%s",&p->name);
        return p;
    }
}
void getNewPersonAdded()
{
    printf("\nNew Person Added");
    printf("\n-------------------");
}
void addBeg()
{
    if(head==NULL)
        printf("\nNo node found");
    else
    {
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else
        {
            ptr->next=head;
            head=ptr;
            getNewPersonAdded();
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nNo node found!");
    else
    {
        struct Person *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCan not allocate memory!!");
        else
        {
            int i,ans=0;;
            struct Person *temp,*prev=NULL;
            printf("\nEnter Serial number which before you want to add a new node : ");
            scanf("%d",&i);
            for(temp=head;(temp);temp=temp->next)
            {
                if(temp->srno==i)
                {
                    if(prev==NULL)
                    {
                        ptr->next=head;
                        head=ptr;
                    }
                    else{
                        ptr->next=temp;
                        prev->next=ptr;
                    }
                    ans=1;
                    getNewPersonAdded();
                    break;
                }
                prev=temp;
            }
            if(ans==0)
            {
                printf("\nSerial number does not exist!");
            }
        }
    }
}
void addEnd()
{
    struct Person *ptr,*temp,*prev;
    ptr=createNode();
    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;

    }
    else
    {
        for(temp=head;(temp);temp=temp->next)
        {
            prev=temp;
        }
        prev->next=ptr;
        ptr->next=NULL;
    }
    getNewPersonAdded();

}
void display()
{
    if(head==NULL)
        printf("\nNo Student!!");
    struct Person *ptr;
    printf("\nStudent are : ");
    for(ptr=head;(ptr);ptr=ptr->next)
    {
        printf("\nSerial number %d",ptr->srno);
        printf("\nName is %s",ptr->name);
        printf("\n----------------------------");
    }
}
void deleteElement()
{
    if(head==NULL)
        printf("\nNo Student!!");
    else{
        struct Person *ptr,*prev;
        int no,ans=0;
        printf("\nEnter Serial no to Delete : ");
        scanf("%d",&no);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(head->next==NULL){
                printf("\nCan not Delete!!");
                ans=1;
            }

            else if(ptr->srno==no)
            {
                if(ptr==head)
                    head=head->next;
                else if(ptr->next==NULL)
                    prev->next=NULL;
                else
                    prev->next=ptr->next;
                printf("\nRoll no Deleted!");
                ans=1;
                free(ptr);
                break;
            }
            ans=1;
            prev=ptr;
        }
        if(ans==0)
            printf("\nRoll no does not exist!!");
    }
}
void main()
{
    int c;
    do{
        printf("\n1. add new node at the beg.");
        printf("\n2. add new node at the middle");
        printf("\n3. add new node at the end");
        printf("\n4. Display");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            addBeg();
        else if(c==2)
            addMid();
        else if(c==3)
            addEnd();
        else if(c==4)
            display();
        else if(c==5)
            deleteElement();
    }while(c!=6);
}
