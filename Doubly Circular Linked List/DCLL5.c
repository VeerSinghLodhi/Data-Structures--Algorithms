#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Student
{
    int rollno,age;
    char name[20],grade;
    struct Student *prev,*next;
}*head,*end;
void getName(struct Student *ptr)
{
        int size,isValid;
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        size=strlen(ptr->name);
        for(int i=0;i<size;i++)
        {
            char ch=ptr->name[i];
            if(!((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')))
            {
                isValid=0;
            }
        }
        while(isValid==0)
        {
            printf("\nInvalid name!!");
            printf("\nEnter valid name : ");
            scanf("%s",&ptr->name);
            size=strlen(ptr->name);
            int res=1;
            for(int i=0;i<size;i++)
            {
                char ch=ptr->name[i];
                if(!((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')))
                {
                    res=0;
                }
            }
            if(res==1)
                isValid=1;
        }
}
void getAge(struct Student *ptr)
{
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid age!!");
            printf("\nPlease Enter valid age : ");
            scanf("%d",&ptr->age);
        }
}
void getGrade(struct Student *ptr)
{
    printf("\nEnter Student Grade : ");
        scanf("%c",&ptr->grade);
        while(!(ptr->grade>='A' && ptr->grade<='F'))
        {
            fflush(stdin);
            printf("\nInvalid grade!!");
            printf("\nPlease Enter valid grade : ");
            scanf("%c",&ptr->grade);//A
        }
}
void add()
{
    struct Student *ptr,*temp;
    int size,isValid;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
        while(ptr->rollno<=0)
        {
            printf("\nInvalid roll no!!");
            printf("\nPlease Enter valid Student Roll no : ");
            scanf("%d",&ptr->rollno);
        }
        if(head!=NULL)
        {
            temp=head;
            do{
                while(temp->rollno==ptr->rollno)
                {
                    printf("\nRoll no already exist in the list ");
                    printf("\nPlease Enter Unique Roll no : ");
                    scanf("%d",&ptr->rollno);
                    temp=head;
                    while(ptr->rollno<=0)
                    {
                        printf("\nInvalid roll no!!");
                        printf("\nPlease Enter valid Student Roll no : ");
                        scanf("%d",&ptr->rollno);
                    }
                }
                temp=temp->next;
            }while(temp!=head);
        }
        getName(ptr);
        getAge(ptr);
        fflush(stdin);
        getGrade(ptr);
        if(head==NULL)
        {
            head=end=ptr;
            ptr->next=head;
            ptr->prev=end;
        }
        else
        {
            int c;
            printf("\nWhere do you want insert?\n");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                head->prev=ptr;
                ptr->next=head;
                head=ptr;
                head->prev=end;
                end->next=head;
            }
            else if(c==2)
            {
                int no,ans=0;
                printf("\nEnter Roll no after which you want insert new record : ");
                scanf("%d",&no);
                temp=head;
                do{
                    if(temp->rollno==no)
                    {
                        ptr->prev=temp;
                        ptr->next=temp->next;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
            }
            else if(c==3)
            {
                ptr->prev=end;
                end->next=ptr;
                end=ptr;
                end->next=head;
                head->prev=end;
            }
        }
        printf("\nNew Student Added\n");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Student Found!!\n");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nStudent Roll no %d",ptr->rollno);
            printf("\nName %s",ptr->name);
            printf("\nAge %d",ptr->age);
            printf("\nGrade %c",ptr->grade);
            printf("\n----------------------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Student Found!!\n");
    else{
        struct Student *ptr;
        ptr=end;
        do{
            printf("\nStudent Roll no %d",ptr->rollno);
            printf("\nName %s",ptr->name);
            printf("\nAge %d",ptr->age);
            printf("\nGrade %c",ptr->grade);
            printf("\n----------------------------------");
            ptr=ptr->prev;
        }while(ptr!=end);
    }
}
void del()
{
    if(head==NULL)
        printf("\nNo Student Found!!\n");
    else{
        int no,ans=0;
        struct Student *ptr=head;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&no);
        do{
            if(ptr->rollno==no)
            {
                if(ptr==head)
                {
                    if(ptr->next==head)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=end;
                        end->next=head;
                    }
                }
                else if(ptr==end)
                {
                    end=end->prev;
                    end->next=head;
                    head->prev=end;
                }
                else{
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                }
                free(ptr);
                ans=1;
                printf("\nStudent Deleted!!");
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nRoll no is not found!!");
    }
}
void update()
{
    if(head==NULL)
        printf("\nNo Student Found!!\n");
    else{
        int c,size,ans=0;
        struct Student *ptr;
        printf("\nEnter Roll no : ");
        scanf("%d",&c);
        ptr=head;
        do{
            if(ptr->rollno==c)
            {
                printf("\nStudent Roll no %d",ptr->rollno);
                printf("\nName %s",ptr->name);
                printf("\nAge %d",ptr->age);
                printf("\nGrade %c",ptr->grade);
                printf("\n----------------------------------");
                printf("\nWhat do you want to update?\n");
                printf("\n1. Name");
                printf("\n2. Age");
                printf("\n3. Grade");
                printf("\n4. All");
                int no;
                printf("\nSelect a choice : ");
                scanf("%d",&no);
                if(no==1)
                {
                    getName(ptr);
                }
                else if(no==2)
                {
                    getAge(ptr);
                }
                else if(no==3)
                {
                    getGrade(ptr);
                }
                else if(no==4)
                {
                    getName(ptr);
                    getAge(ptr);
                    getGrade(ptr);
                }
                printf("\nStudent Details Updated!!\n");
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nRoll no is not found!!");
    }
}
void main()
{
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse (Head to End)");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete ");
        printf("\n5. Update");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            rTraverse();
        else if(c==4)
            del();
        else if(c==5)
            update();
    }while(c!=6);
}
