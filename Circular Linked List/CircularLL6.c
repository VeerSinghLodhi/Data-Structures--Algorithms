#include<stdio.h>
#include<stdlib.h>
struct Person
{
    int data;
    char name[20];
    struct Person *next;
}*head;
void add()
{
    struct Person *ptr,*temp;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
            int c;
            printf("\nWhere do you want to insert?\n");
            printf("\n1. At the Beginning");
            printf("\n2. At the Middle");
            printf("\n3. At the End\n");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                temp=head;//80
                while(temp->next!=head)
                    temp=temp->next;

                ptr->next=head;//80
                head=ptr;//110
                temp->next=head;//110
            }
            else if(c==2)
            {
                int no,ans=0;
                printf("\nEnter Serial number after which you want to insert new record : ");
                scanf("%d",&no);
                temp=head;
                do{
                    if(temp->data==no)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0)
                    printf("\nSerial no. is not found!");
            }
            else if(c==3)
            {
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                temp->next=ptr;
                ptr->next=head;
            }
        }
        printf("\nNew Person Added!!\n");
    }
    printf("\nHead is %d",*head);
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Person *ptr;
        ptr=head;//30
        do{
            printf("\nData is %d",ptr->data);
            printf("\nName is %s",ptr->name);
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
            struct Person *ptr,*temp,*prev;
            printf("\nEnter Serial number to delete : ");
            scanf("%d",&no);
            ptr=head;
            do{
                if(ptr->data==no)
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
void search()
{
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        int c,ans=0;
        struct Person *ptr;
        printf("\nEnter Serial : ");
        scanf("%d",&c);
        ptr=head;
        do{
            if(ptr->data==c)
            {
                printf("\nData is %d",ptr->data);
                printf("\nName is %s",ptr->name);
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nData is not found!!");
        printf("\n");
    }
}
void update()
{
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        int c,ans=0;
        printf("\nEnter Serial number to update : ");
        scanf("%d",&c);
        struct Person *ptr;
        ptr=head;
        do{
            if(ptr->data==c)
            {
                printf("\nData is %d",ptr->data);
                printf("\nName is %s",ptr->name);
                printf("\n---------------------");
                printf("\nNew Data :");
                printf("\nEnter New Name : ");
                scanf("%s",&ptr->name);
                ans=1;
                printf("\nUpdated");
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nSerial number is not found!!");
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
        printf("\n4. Search");
        printf("\n5. Update");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            del();
        else if(c==4)
            search();
        else if(c==5)
            update();
    }while(c!=6);
}

