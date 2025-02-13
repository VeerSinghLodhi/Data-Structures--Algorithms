#include<stdio.h>
struct Person
{
    int srno,age;
    char name[20],address[50];
    char gender;
    struct Person *next;
}*head;
void add()
{
    struct Person *p,*ptr,*prev;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
    {
        printf("\nCan not allocate memory!!");
    }
    else
    {
        printf("\nEnter Serial number : ");
        scanf("%d",&p->srno);
        printf("\nEnter Name : ");
        scanf("%s",&p->name);
        fflush(stdin);
        printf("\nEnter Address : ");
        scanf("%s",&p->address);
        fflush(stdin);
        printf("\nEnter Gender : ");
        scanf("%c",&p->gender);
        printf("\nEnter Age : ");
        scanf("%d",&p->age);
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
    if(head==NULL)
    {
        printf("\nDoes not exist any element in the linked list!!");
        return;
    }
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        printf("\nSerial number : %d",ptr->srno);
        printf("\nName is : %s",ptr->name);
        printf("\nGender is : %c",ptr->gender);
        printf("\nAge is : %d",ptr->age);
        printf("\nAddress is : %s",ptr->address);
        printf("\n=========================");
    }
}
void deleteElement()
{
    struct Person *ptr,*prev;
    int no,ans=0;
    printf("\nEnter serial number to delete : ");
    scanf("%d",&no);
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->srno==no)
        {
            if(ptr==head)
                head=head->next;
            else if(ptr->next==NULL)
                prev->next=NULL;
            else
                prev->next=ptr->next;
            ans=1;
            printf("\nElement Deleted!!");
            printf("\n---------------------------");
            free(ptr);
            break;
        }
        prev=ptr;
    }
    if(ans==0)
    {
        printf("\nSerial number does not exist!!");
        printf("\n--------------------------------");
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new ");
        printf("\n2. Show all ");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            show();
        else if(c==3)
            deleteElement();
        else
            printf("\nInvalid Choice!!\n");
    }while(c!=4);
}

