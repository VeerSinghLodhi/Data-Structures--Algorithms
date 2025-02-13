#include<stdio.h>
struct Person
{
    char name[20];
    char gender;
    int age;
    struct Person *next;
}*start;
void add()
{
    struct Person *p,*s,*prev;
    p=(struct Person*)malloc(sizeof(struct Person));
    if(p==NULL)
        printf("\nCan not Allocate Memory!");
    else
    {
        printf("\nEnter Name : ");
        scanf("%s",&p->name);
        printf("\nEnter Age : ");
        scanf("%d",&p->age);
        fflush(stdin);
        printf("\nEnter Gender : ");
        scanf("%c",&p->gender);
        if(start==NULL)
        {
            start=p;
            p->next=NULL;
        }
        else
        {
            for(s=start;s!=NULL;s=s->next)
                prev=s;

            prev->next=p;
            p->next=NULL;
        }
    }
}
void show()
{
    struct Person *ptr;
    for(ptr=start;ptr!=NULL;ptr=ptr->next)
    {
        printf("\nName is %s",ptr->name);
        printf("\nAge is %d",ptr->age);
        printf("\nGender is %c",ptr->gender);
        printf("\n---------------------");
    }
}
void main()
{
    start=NULL;
    int c;
    do{
        printf("\n1. Add new Person ");
        printf("\n2. Show all Person");
        printf("\n3. Exit!");
        printf("\nSelect a Choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            show();
    }while(c!=3);
}
