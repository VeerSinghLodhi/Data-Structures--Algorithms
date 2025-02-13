#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[20];
    struct Student *next;
}*head;
void add()
{
    struct Student *s,*p,*prev;
    s=(struct Student*)malloc(sizeof(struct Student));
    printf("\nAddress is %d\n",s);
    if(s==NULL)
        printf("\nCan not allocate memory!!");
    else
    {
        printf("\nEnter Roll no : ");
        scanf("%d",&s->rollno);
        printf("\nEnter name : ");
        scanf("%s",&s->name);
        if(head==NULL)
        {
            head=s;
            s->next=NULL;
        }
        else
        {
            for(p=head;p!=NULL;p=p->next)
                prev=p;

            prev->next=s;
            s->next=NULL;
        }
    }
}
void show()
{
    struct Student *veer;
    for(veer=head;veer!=NULL;veer=veer->next)
    {
        printf("\nRoll no : %d",veer->rollno);
        printf("\nName : %s",veer->name);
        printf("\n-------------------------------");
    }
}
void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student ");
        printf("\n2. Show all Student");
        printf("\n3. Exit");
        printf("\nSelect a Choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            show();
    }while(c!=3);
    printf("\nThank You!!");
}
