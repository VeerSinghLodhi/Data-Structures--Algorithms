#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Student
{
    int rollno;
    char name[20];
    struct Student *prev,*next;
}*head,*end;
void setRollno(struct Student *ptr)
{
    struct Student *temp;
    printf("\nEnter Roll no : ");
    scanf("%d",&ptr->rollno);
    while(ptr->rollno<=0)
    {
        printf("\nInvalid Roll no!!");
        printf("\nPlease Enter valid roll no : ");
        scanf("%d",&ptr->rollno);
    }
    if(head!=NULL)
    {
        temp=head;
        do{
            while(temp->rollno==ptr->rollno)
            {
                printf("\nRoll no Already Exist in the list!!");
                printf("\nPlease Enter Unique Roll no : ");
                temp=head;
                scanf("%d",&ptr->rollno);
                while(ptr->rollno<=0)
                {
                    printf("\nInvalid Roll no!!");
                    printf("\nPlease Enter valid roll no : ");
                    scanf("%d",&ptr->rollno);
                }
            }
            temp=temp->next;
        }while(temp!=head);
    }
}
void setName(struct Student *ptr)
{
    int size,isValid=1;
    printf("\nEnter Student Name : ");
    scanf("%s",&ptr->name);
    size=strlen(ptr->name);
    for(int i=0;i<size;i++)
    {
        char ch=ptr->name[i];
        if(!((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')))
            isValid=0;
    }
    while(isValid==0)
    {
        printf("\nInvalid name!!");
        printf("\nPlease Enter valid name : ");
        scanf("%s",&ptr->name);
        int res=1;
        size=strlen(ptr->name);
        for(int i=0;i<size;i++)
        {
            char ch=ptr->name[i];
            if(!((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')))
                res=0;
        }
        if(res==1)
            isValid=1;
    }
}
void add()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!");
    else{
        setRollno(ptr);
        setName(ptr);
        if(head==NULL)
        {
            head=end=ptr;
            ptr->next=head;
            ptr->prev=end;
        }
        else{
            ptr->prev=end;
            end->next=ptr;
            end=ptr;
            end->next=head;
            head->prev=end;
        }
        printf("\nNew Student Added!!");
    }
}
void traverse()
{
    if(head==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nRoll no %d",ptr->rollno);
            printf("\nName is %s",ptr->name);
            printf("\n---------------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void rTraverse()
{
    if(head==NULL)
        printf("\nNo Students found!!");
    else{
        struct Student *ptr;
        ptr=end;
        do{
            printf("\nRoll no %d",ptr->rollno);
            printf("\nName is %s",ptr->name);
            printf("\n---------------------------");
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
        printf("\nNo Students Found!!");
    else{
        int no,ans=0;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&no);
        struct Student *ptr;
        ptr=head;
        do{
            if(ptr->rollno==no)
            {
                printf("\nRoll no %d",ptr->rollno);
                printf("\nName is %s",ptr->name);
                printf("\n---------------------------");
                setName(ptr);
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nRoll no is not found!!\n");
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
