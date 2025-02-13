#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id,age;
    char name[20],grade;
    struct Student *next;
}*head;
void add()
{
    struct Student *ptr,*temp;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Student ID : ");
        scanf("%d",&ptr->id);
        while(ptr->id<=0)
        {
            printf("\nInvalid ID!!\n");
            printf("\nEnter Valid ID : ");
            scanf("%d",&ptr->id);
        }
        if(head!=NULL){
            temp=head;
            do{
                while(temp->id==ptr->id)
                {
                    printf("\nStudent ID Already Exist in the list !!");
                    printf("\nPlease Enter Unique ID : ");
                    scanf("%d",&ptr->id);
                }
                temp=temp->next;
            }while(temp!=head);
        }

        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid Age!!\n");
            printf("\nPlease Enter valid age : ");
            scanf("%d",&ptr->age);
        }
        fflush(stdin);
        printf("\nEnter Student Grade : ");
        scanf("%c",&ptr->grade);
        while(!(ptr->grade>='A' && ptr->grade<='F'))
        {
            printf("\nInvalid Grade!!");
            fflush(stdin);
            printf("\nEnter Valid Grade : ");
            scanf("%c",&ptr->grade);
        }
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else{
            int c;
            printf("\nWhere do you want to insert?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a Choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                ptr->next=head;
                head=ptr;
                temp->next=head;
            }
            else if(c==2)
            {
                int no,ans=0;
                printf("Enter ID after which you want to insert new record : ");
                scanf("%d",&no);
                temp=head;
                do{
                    if(temp->id==no)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0)
                    printf("\nStudent ID is not found!!");
            }
            else if(c==3)
            {
                temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->next=head;
            }
        }
        printf("\nNew Student Added!!\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nStudent ID %d",ptr->id);
            printf("\nName is %s",ptr->name);
            printf("\nAge is %d",ptr->age);
            printf("\nGrade is %c",ptr->grade);
            printf("\n-----------------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Student Found!!\n");
    else{
        if(head==head->next)
            printf("\nCan not Delete!!\n");
        else{
            struct Student *ptr,*temp,*prev;
            int no,ans=0;
            printf("\nEnter Student ID to delete : ");
            scanf("%d",&no);
            ptr=head;
            do{
                if(ptr->id==no)
                {
                    if(ptr==head)
                    {
                        temp=head;
                        while(temp->next!=head)
                            temp=temp->next;
                        head=head->next;
                        temp->next=head;
                    }
                    else if(ptr->next==head)
                    {
                        prev->next=head;
                    }
                    else {
                        prev->next=ptr->next;
                    }
                    free(ptr);
                    printf("Student ID Deleted!!\n");
                    ans=1;
                    break;
                }
                prev=ptr;
                ptr=ptr->next;
            }while(ptr!=head);
            if(ans==0)
                printf("\nStudent ID is not found!!\n");
        }
    }
}
void search()
{
    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr;
        int no,ans=0;
        printf("\nEnter Student ID : ");
        scanf("%d",&no);
        ptr=head;
        do{
            if(ptr->id==no)
            {
                printf("\nStudent ID %d",ptr->id);
                printf("\nName is %s",ptr->name);
                printf("\nAge is %d",ptr->age);
                printf("\nGrade is %c",ptr->grade);
                printf("\n-----------------------------");
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nStudent ID is not found!!\n");
    }
}
void update()
{
    if(head==NULL)
        printf("\nNO Students Found!!\n");
    else{
        struct Student *ptr;
        int no,ans=0;
        printf("\nEnter Student ID To Update : ");
        scanf("%d",&no);
        ptr=head;
        do{
            if(ptr->id==no)
            {
                printf("\nData is :->");
                printf("\nStudent ID %d",ptr->id);
                printf("\nName is %s",ptr->name);
                printf("\nAge is %d",ptr->age);
                printf("\nGrade is %c",ptr->grade);
                printf("\n-----------------------------");
                int v;
                printf("\nWhat do you want to update ?");
                printf("\n1. Student Name");
                printf("\n2. Student Age");
                printf("\n3. Student Grade");
                printf("\n4. Student All Details");
                printf("\nSelect a choice : ");
                scanf("%d",&v);
                if(v==1)
                {
                    printf("\nEnter new name : ");
                    scanf("%s",&ptr->name);
                }
                else if(v==2)
                {
                    printf("\nEnter new age : ");
                    scanf("%d",&ptr->age);
                    while(ptr->age<=0)
                    {
                        printf("\nInvalid Age!!\n");
                        printf("\nPlease Enter valid age : ");
                        scanf("%d",&ptr->age);
                    }
                }
                else if(v==3)
                {
                    fflush(stdin);
                    printf("\nEnter new grade : ");
                    scanf("%c",&ptr->grade);
                    while(!(ptr->grade>='A' && ptr->grade<='F'))
                    {
                        printf("\nInvalid Grade!!");
                        fflush(stdin);
                        printf("\nEnter Valid Grade : ");
                        scanf("%c",&ptr->grade);
                    }
                }
                else if(v==4){
                    printf("\nEnter Student Name : ");
                    scanf("%s",&ptr->name);
                    printf("\nEnter Student Age : ");
                    scanf("%d",&ptr->age);
                    while(ptr->age<=0)
                    {
                        printf("\nInvalid Age!!\n");
                        printf("\nPlease Enter valid age : ");
                        scanf("%d",&ptr->age);
                    }
                    fflush(stdin);
                    printf("\nEnter Student Grade : ");
                    scanf("%c",&ptr->grade);
                    while(!(ptr->grade>='A' && ptr->grade<='F'))
                    {
                        printf("\nInvalid Grade!!");
                        fflush(stdin);
                        printf("\nEnter Valid Grade : ");
                        scanf("%c",&ptr->grade);
                    }
                }
                printf("\nStudent Details Updated!!");
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nStudent ID is not found!!\n");
    }
}
void getTotalRecords()
{
    if(head==NULL)
        printf("\nNo Student Found!!");
    else{
        struct Student *ptr;
        int count=0;
        ptr=head;
        do{
            count++;
            ptr=ptr->next;
        }while(ptr!=head);
        printf("\nTotal Records --> %d",count);
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add New Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Search");
        printf("\n5. Update");
        printf("\n6. Total Records");
        printf("\n7. Exit");
        printf("\nSelect a Choice : ");
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
        else if(c==6)
            getTotalRecords();
    }while(c!=7);
}
