#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id,age;
    char name[20],grade;
    struct Student *prev,*next;
}*head,*end;
void add()
{
    struct Student *ptr,*temp;
    ptr=(struct Student *)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Student ID : ");
        scanf("%d",&ptr->id);
        while(ptr->id<=0)
        {
            printf("\nInvalid ID");
            printf("\nEnter valid Student ID : ");
            scanf("%d",&ptr->id);
        }
        for(temp=head;(temp);temp=temp->next)
        {
            while(temp->id==ptr->id)
            {
                printf("\nStudent ID already exist in the list");
                printf("\nEnter Different Valid ID : ");
                scanf("%d",&ptr->id);
                while(ptr->id<=0)
                {
                    printf("\nInvalid ID");
                    printf("\nEnter valid Student ID : ");
                    scanf("%d",&ptr->id);
                }
            }
        }
        printf("\nEnter Student name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid AGE");
            printf("\nEnter Valid Student Age : ");
            scanf("%d",&ptr->age);
        }
        fflush(stdin);
        printf("\nEnter Student Grade : ");
        scanf("%c",&ptr->grade);
        while(!(ptr->grade>='A' && ptr->grade<='F'))
        {
            printf("\nInvalid Grade!!");
            fflush(stdin);
            printf("\nEnter valid grade : ");
            scanf("%c",&ptr->grade);
        }
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            ptr->next=NULL;
            ptr->prev=NULL;
        }
        else{
            int c;
            printf("\nWhere do you want insert new Student record \n");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect your choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                ptr->next=head;
                head->prev=ptr;
                head=ptr;
                head->prev=NULL;
            }
            else if(c==2)
            {
                int no,ans=0;
                printf("\nEnter Student ID after which you want to insert new record : ");
                scanf("%d",&no);
                for(temp=head;(temp);temp=temp->next)
                {
                    if(temp->id==no)
                    {
                        ptr->prev=temp;
                        ptr->next=temp->next;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                        ans=1;
                        printf("\nStudent Record Added");
                        break;
                    }
                }
                if(ans==0)
                    printf("\nSorry Student ID is not found!!\n");
            }
            else if(c==3){
                end->next=ptr;
                ptr->next=end;
                end=ptr;
                end->next=NULL;
            }
        }
    }
}
void deleteElement()
{
    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr;
        int no,ans=0;
        printf("\nEnter Student ID to Delete : ");
        scanf("%d",&no);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==no)
            {
                if(ptr==head)
                {
                    head=head->next;
                    head->prev=NULL;
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
                free(ptr);
                ans=1;
                printf("\nStudent Record Deleted\n");
                break;
            }
        }
        if(ans==0)
            printf("\nStudent ID is not found");
    }

}
void traverse()
{
    if(head==NULL)
        printf("\nNo Student Found");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nStudent ID is %d",ptr->id);
            printf("\nStudent Name is %s",ptr->name);
            printf("\nStudent Age is %d",ptr->age);
            printf("\nStudent Grade is %c",ptr->grade);
            printf("\n--------------------------------");
        }
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Student Found");
    else{
        struct Student *ptr;
        for(ptr=end;(ptr);ptr=ptr->prev)
        {
            printf("\nStudent ID is %d",ptr->id);
            printf("\nStudent Name is %s",ptr->name);
            printf("\nStudent Age is %d",ptr->age);
            printf("\nStudent Grade is %c",ptr->grade);
            printf("\n--------------------------------");
        }
    }
}
void update()
{

}
void main()
{
    int c;
    head=end=NULL;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Delete Student");
        printf("\n3. Traverse (Head to End)");
        printf("\n4. Traverse (End to Head)");
        printf("\n5. Update");
        printf("\n6. Exit");
        printf("\nSelect your choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            deleteElement();
        else if(c==3)
            traverse();
        else if(c==4)
            rTraverse();
        else if(c==5)
            update();
    }while(c!=6);
}
