#include<stdio.h>
#include<stdlib.h>
struct Student {
    int data;
    struct Student *next;
}*head;
void add(){
    struct Student *ptr,*temp,*prev;
    int c;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->data);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else{
            printf("\nWhere do you want insert??\n");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                ptr->next=head;
                head=ptr;
            }
            else if(c==2)
            {
                int v;
                printf("\nEnter Roll no after which you want insert new record : ");
                scanf("%d",&v);
                for(temp=head;(temp);temp=temp->next)
                {
                    if(temp->data==v)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                        break;
                    }
                }
            }
            else if(c==3)
            {
                for(temp=head;(temp);temp=temp->next)
                {
                    prev=temp;
                }
                prev->next=ptr;
                ptr->next=NULL;
            }
        }
        printf("\nNew Student Added!!");
    }
}
void traverse(){
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Student *temp;
        for(temp=head;(temp);temp=temp->next)
        {
            printf("\nData is %d",temp->data);
            printf("\n------------------------");
        }
    }
}
void delStudent(){
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Student *temp,*prev;
        int c,ans=0;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&c);
        for(temp=head;(temp);temp=temp->next)
        {
            if(temp->data==c)
            {
                if(temp==head)
                    head=head->next;
                else if(temp->next==NULL)
                    prev->next=NULL;
                else
                    prev->next=temp->next;
                ans=1;
                free(temp);
                printf("\nDeleted!!");
                break;
            }
            prev=temp;
        }
        if(ans==0)
            printf("\nRoll no is not found!!");
    }
}
void main(){
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            delStudent();
    }while(c!=4);
}
