
#include<stdio.h>
struct Person
{
    int srno;
    char name[20];
    struct Person *next;
}*head;
void add()
{
    struct Person *p,*ptr,*prev;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        printf("\nCan not allocate memory!");
    else
    {
        printf("\nEnter Serial number : ");
        scanf("%d",&p->srno);
        printf("\nEnter name : ");
        scanf("%s",&p->name);
        if(head==NULL)
        {
            head=p;
            p->next=NULL;
        }
        else
        {
            for(ptr=head;ptr!=NULL;ptr=ptr->next)
            {
                prev=ptr;
            }
            prev->next=p;
            p->next=NULL;
        }

    }
}
void show()
{
    struct Person *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("\nDoes not exist any element in the linked list!!");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\nSerial number : %d",ptr->srno);
        printf("\nName is : %s",ptr->name);
        printf("\n==============================");
        ptr=ptr->next;
    }
}
void del()
{
    int c,ans=0;
    struct Person *ptr,*prev;
    printf("\nEnter serial number to delete : ");
    scanf("%d",&c);
    ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->srno==c)
        {
            if(ptr->next==NULL)//asdfghjkl;
                prev->next=NULL;
            else if(ptr==head)
                head=head->next;
            else
                prev->next=ptr->next;
            free(ptr);
            ans=1;
            printf("\nElement Deleted!!");
            break;
        }
        prev=ptr;
        ptr=ptr->next;
    }
    if(ans==0)
    {
        printf("\nSorry Serial number does not exist!!\n");
        printf("\n---------------------------------------\n");
    }
}
void main()
{
    head=NULL;
    int choice;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Show all Person");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&choice);
        if(choice==1)
            add();
        else if(choice==2)
            show();
        else if(choice==3)
            del();
    }while(choice!=4);
}
