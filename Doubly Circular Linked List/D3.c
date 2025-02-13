#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int data;
    char name[30];
    struct Student *prev,*next;
}*head,*end;
struct Student *createNode()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        return NULL;
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        return ptr;
    }
}
void add(){
    struct Student *ptr;
    ptr=createNode();
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{

        if(head==NULL){
            head=end=ptr;
            ptr->next=ptr->prev=NULL;
        }
        else{
            ptr->prev=end;
            end->next=ptr;
            end=ptr;
            end->next=NULL;
        }
    }
}
void headtoEnd(){
    if(head==NULL)
        printf("\nLinked list is empty!!");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nData is %d",ptr->data);
            printf("\nName is %s",ptr->name);
            printf("\n----------------------");
        }
    }
}
void endtoHead(){
    if(head==NULL)
        printf("\nLinked list is empty!!");
    else{
        struct Student *ptr;
        for(ptr=end;(ptr);ptr=ptr->prev)
        {
            printf("\nData is %d",ptr->data);
            printf("\nName is %s",ptr->name);
            printf("\n----------------------");
        }
    }
}
void del(){
    if(head==NULL)
        printf("\nLinked list is empty!!");
    else{
        int c,ans=0;
        printf("\nEnter data to delete :");
        scanf("%d",&c);
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next){
            if(ptr->data==c)
            {
                if(head==ptr)
                {
                    if(head->next==NULL)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=NULL;
                    }
                }
                else if(ptr==end)
                {
                    end=end->prev;
                    end->next=NULL;
                }
                else{
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                ans=1;
                free(ptr);
                printf("\nDeleted!!");
                break;
            }
        }
        if(ans==0)
            printf("\nData is not found!!");
    }
}
void addBeg()
{
    if(head==NULL)
        printf("\nLinked list is empty!!");
    else{
        struct Student *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCannot allocate memory!!");
        else{
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
            head->prev=NULL;
            printf("\nNew Student Added at the Begging");
        }
    }
}
void addMid()
{
    if(head==NULL)
        printf("\nLinked list is empty!!");
    else{
        struct Student *ptr;
        ptr=createNode();
        if(ptr==NULL)
            printf("\nCannot allocate memory!!");
        else{
            int c,ans=0;
            printf("\nEnter Data after which you want insert new record : ");
            scanf("%d",&c);
            struct Student *temp;
            for(temp=head;(temp);temp=temp->next)
            {
                if(temp->data==c)
                {
                    ptr->next=temp->next;
                    ptr->prev=temp;
                    temp->next->prev=ptr;
                    temp->next=ptr;
                    printf("\nNew Student Added");
                    ans=1;
                    break;
                }
            }
            if(ans==0)
                printf("\nData is not found!!");
        }
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse(Head to End)");
        printf("\n3. Traverse(End to Head)");
        printf("\n4. Delete");
        printf("\n5. Add at the Begging");
        printf("\n6. Add at the Specific position");
        printf("\n7. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            headtoEnd();
        else if(c==3)
            endtoHead();
        else if(c==4)
            del();
        else if(c==5)
            addBeg();
        else if(c==6)
            addMid();
        else if(c>7 || c<=0){
            printf("\nInvalid choice");
            printf("\nSelect valid choice\n");
        }
    }while(c!=7);
}
