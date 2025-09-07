#include<stdio.h>
struct Student
{
    int rollno;
    struct Student *next;
}*head;
void addStudent()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
    {
        printf("\nCannot allocated memory!");
    }
    else
    {
        int no;
        printf("\nEnter Student Roll no. : ");
        scanf("%d",&ptr->rollno);
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else
        {
            int c;
            printf("\nSelect a choice");
            printf("\n1. At the Beginning");
            printf("\n2. At Middle ");
            printf("\n3. At the end");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1)
            {
                ptr->next=head;
                head=ptr;
                printf("\nNew Student Added");
            }
            else if(c==2)
            {
                int n;
                printf("\nEnter roll no. after which you want insert new record : ");
                scanf("%d",&n);
                struct Student *temp,*prev;
                for(temp=head;(temp);temp=temp->next){
                    if(temp->rollno==n)
                    {
                        printf("Entered inside loop");
                        ptr->next=prev->next;
                        prev->next=ptr;
                        printf("\nNew Student Added!");
                        break;
                    }
                    prev=temp;
                }
            }
            else if(c==3)
            {
                struct Student *temp,*p;
                for(temp=head; (temp); temp=temp->next)
                {
                    p=temp;
                }
                p->next=ptr;
                ptr->next=NULL;
                printf("\nNew Student Added");
            }
            else
            {
                printf("\nInvalid choice!");
            }
        }

    }
}

void showAllStudents()
{
    if(head==NULL)
    {
        printf("\n Student Found!!");
        return ;
    }
    struct Student *temp=head;
    for(temp=head; (temp); temp=temp->next)
    {
        printf("\nStudent roll no. : %d",temp->rollno);
        printf("\n---------------------------");
    }
}

int main()
{
    head=NULL;
    int ch;
    do
    {
        printf("\n---- Choices ----");
        printf("\n1. Add new student");
        printf("\n2. Show all students");
        printf("\n3. Exit");
        printf("\n Select a choice : ");
        scanf("%d",&ch);
        if(ch==1)
            addStudent();
        else if(ch==2)
            showAllStudents();
        else if(ch==3)
            printf("\nExiting...");
        else
            printf("\nInvalid choice!!");
    }
    while(ch!=3);
}
