#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id,age;
    char name[30],grade;
    struct Student *prev,*next;
}*head,*end;

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
            printf("\nPlease Enter Valid Student ID : ");
            scanf("%d",&ptr->id);
        }
        for(temp=head;(temp);temp=temp->next)
        {
            if(temp->id==ptr->id)
            {
                while(temp->id==ptr->id){
                    printf("\nStudent ID already exist in the list!!\n");
                    printf("\nEnter Student ID : ");
                    scanf("%d",&ptr->id);
                    while(ptr->id<=0)
                    {
                        printf("\nInvalid ID!!\n");
                        printf("\nPlease Enter Valid Student ID : ");
                        scanf("%d",&ptr->id);
                    }
                }
            }
        }
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid age!!\n");
            printf("\nPlease Enter Valid Student Age : ");
            scanf("%d",&ptr->age);
        }
        fflush(stdin);
        printf("\nEnter Student Grade : ");
        scanf("%c",&ptr->grade);
        while(!((ptr->grade>='A' && ptr->grade<='F') || (ptr->grade>='a' && ptr->grade<='f')))
        {
            printf("\nInvalid Grade!!\n");
            printf("\nPlease Enter Valid Student Grade : ");
            fflush(stdin);
            scanf("%c",&ptr->grade);
        }
        if(head==NULL)
        {
            head=ptr;
            end=ptr;
            ptr->prev=NULL;
            ptr->next=NULL;
        }
        else{
            int c;
            printf("\nWhere do you want to insert ??\n");
            printf("\n1. At the Beginning");
            printf("\n2. At a Specific Position");
            printf("\n3. At the End\n");
            printf("\nSelect your Choice : ");
            scanf("%d",&c);
            if(c==1){
                head->prev=ptr;
                ptr->next=head;
                head=ptr;
                ptr->prev=NULL;
            }
            else if(c==2)
            {
                int no;
                printf("\nEnter Student ID after which you want to add a new Student : ");
                scanf("%d",&no);
                for(temp=head;(temp);temp=temp->next)
                {
                    if(temp->id==no)
                    {
                        ptr->prev=temp;
                        ptr->next=temp->next;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                    }
                }
            }
            else{
                end->next=ptr;
                ptr->prev=end;
                ptr->next=NULL;
                end=ptr;
            }
        }
        printf("\nNew Student Added\n");
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        int sid,ans=0;
        printf("\nEnter Student ID to delete : ");
        scanf("%d",&sid);
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)
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
                printf("\nStudent Deleted!!\n");
                break;
            }
        }
        if(ans==0)
            printf("\nStudent ID is not Found!!\n");
    }
}
void search()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *ptr;
        int sid,ans=0;
        printf("\nEnter Student ID : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)
            {
                printf("\nStudent id %d",ptr->id);
                printf("\nStudent Name %s",ptr->name);
                printf("\nStudent Age %d",ptr->age);
                printf("\nStudent Grade %c",ptr->grade);
                ans=1;
                printf("\n----------------------------\n");
            }
        }
        if(ans==0)
            printf("\nStudent ID is not Found!!\n");
    }
}
void update()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        int sid,ans=0;
        struct Student *ptr;
        printf("\nEnter Student ID : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)
            {
                printf("\nStudent Details\n");
                printf("\nStudent id %d",ptr->id);
                printf("\nStudent Name %s",ptr->name);
                printf("\nStudent Age %d",ptr->age);
                printf("\nStudent Grade %c",ptr->grade);
                printf("\n----------------------------\n");
                printf("\nWhat do you want to Update??\n");
                printf("\n1. Name ");
                printf("\n2. Age");
                printf("\n3. Grade");
                int u;
                printf("\nSelect your choice : ");
                scanf("%d",&u);
                if(u==1){
                    printf("\nEnter New Name : ");
                    scanf("%s",&ptr->name);
                }
                else if(u==2){
                    printf("\nEnter new Age : ");
                    scanf("%d",&ptr->age);
                    while(ptr->age<=0)
                    {
                        printf("\nInvalid age!!\n");
                        printf("\nPlease Enter Valid Student Age : ");
                        scanf("%d",&ptr->age);
                    }
                }
                else if(u==3){
                    printf("\nEnter New Grade : ");
                    fflush(stdin);
                    scanf("%c",&ptr->grade);
                    while(!((ptr->grade>='A' && ptr->grade<='F') || (ptr->grade>='a' && ptr->grade<='f')))
                    {
                        printf("\nInvalid Grade!!\n");
                        printf("\nPlease Enter Valid Student Grade : ");
                        fflush(stdin);
                        scanf("%c",&ptr->grade);
                    }
                }
                else{
                    printf("\nInvalid choice!!\n");
                    printf("Student could not be updated!!\n");
                }
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nStudent ID is not Found!!\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nStudent id %d",ptr->id);
            printf("\nStudent Name %s",ptr->name);
            printf("\nStudent Age %d",ptr->age);
            printf("\nStudent Grade %c",ptr->grade);
            printf("\n----------------------------\n");
        }
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Student *ptr;
        for(ptr=end;(ptr);ptr=ptr->prev)
        {
            printf("\nStudent id %d",ptr->id);
            printf("\nStudent Name %s",ptr->name);
            printf("\nStudent Age %d",ptr->age);
            printf("\nStudent Grade %c",ptr->grade);
            printf("\n----------------------------\n");
        }
    }
}
void countTotalRecords()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *ptr;
        int count=0;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            count++;
        }
        printf("\nTotal Student : %d\n",count);
    }
}
void findMinAndMaxAge()
{
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *ptr;
        int minAge,maxAge;
        minAge=head->age;
        maxAge=head->age;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(minAge>ptr->age)
                minAge=ptr->age;
            if(maxAge<ptr->age)
                maxAge=ptr->age;
        }
        printf("\nMinimum age Student is %d",minAge);
        printf("\nMaximum age Student is %d\n",maxAge);
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Insert a Record");
        printf("\n2. Delete a Record");
        printf("\n3. Search For a Record");
        printf("\n4. Update a Record");
        printf("\n5. Display All Records(Head to End)");
        printf("\n6. Display All Records(End to Head)");
        printf("\n7. Count Total Records");
        printf("\n8. Find Minimum and Maximum Age");
        printf("\n9. Exit");
        printf("\nSelect your Choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            del();
        else if(c==3)
            search();
        else if(c==4)
            update();
        else if(c==5)
            traverse();
        else if(c==6)
            rTraverse();
        else if(c==7)
            countTotalRecords();
        else if(c==8)
            findMinAndMaxAge();
        else
            printf("\nRadhe Radhe\n");
    }while(c!=9);
}
