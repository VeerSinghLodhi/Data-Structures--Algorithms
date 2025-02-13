#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int srno;
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr,*temp;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter serial number : ");
        scanf("%d",&ptr->srno);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
            temp=head;
            while(temp->next!=head)
                temp=temp->next;
            temp->next=ptr;
            ptr->next=head;
        }
        printf("\nNew Student Added!!\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Student found!!\n");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nSerial number %d",ptr->srno);
            ptr=ptr->next;
        }while(ptr!=head);
        printf("\n");
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        if(head==head->next)
            printf("\nCan not delete!!");
        else{
            int no,ans=0;
            struct Student *ptr,*temp,*prev;
            printf("\nEnter Serial number to delete : ");
            scanf("%d",&no);
            ptr=head;
            do{
                if(ptr->srno==no)
                {
                    if(ptr==head)
                    {
                        temp=head;
                        while(temp->next!=head)
                            temp=temp->next;

                        head=head->next;
                        temp->next=head;//new head address
                    }
                    else if(ptr->next==head)
                    {
                        prev->next=head;
                    }
                    else{
                        prev->next=ptr->next;
                    }
                    free(ptr);
                    printf("\nStudent Deleted!!");
                    ans=1;
                    break;
                }
                prev=ptr;
                ptr=ptr->next;
            }while(ptr!=head);
            if(ans==0)
                printf("\nSerial number is not found!!");
        }
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add New Student ");
        printf("\n2. Traverse");
        printf("\n3. Delete ");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            del();
    }while(c!=4);
}
