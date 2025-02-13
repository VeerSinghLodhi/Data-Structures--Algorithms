#include<stdio.h>
#include<stdlib.h>
struct Student{
    int id,age;
    char name[30],grade;
    struct Student *next;
}*head;

void addNewStudent(){

    struct Student *ptr,*temp,*prev;
     ptr=(struct Student *)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCan not allocate memory!!");
    else{
        printf("\nEnter Student ID : ");
        scanf("%d",&ptr->id);
        while(ptr->id<=0)
        {
            printf("\nInvalid ID!\n");
            printf("\nEnter Valid ID : ");
            scanf("%d",&ptr->id);
        }
        for(temp=head;(temp);temp=temp->next){  //  (temp) = temp!=NULL
            if(temp->id==ptr->id){
                printf("\nStudent Id already exist in the list!!\n");
                return;
            }
        }
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        printf("\nEnter Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid Age!!\n");
            printf("\nEnter Valid Age : ");
            scanf("%d",&ptr->age);
        }
        fflush(stdin);
        printf("\nEnter Grade : ");
        scanf("%c",&ptr->grade);
        while(!((ptr->grade>='A' && ptr->grade<='F') || (ptr->grade>='a' && ptr->grade<='f')))
        {
            printf("\nInvalid Grade!!\n");
            fflush(stdin);
            printf("\nEnter valid Grade : ");
            scanf("%c",&ptr->grade);
        }
        if(head==NULL)
        {
            head=ptr;
            ptr->next=NULL;
        }
        else{
             int c;
             printf("\nWhere do you want to insert ?\n");
             printf("\n1. At the beginning");
             printf("\n2. At a specific position");
             printf("\n3. At the end");
             printf("\nSelect your choice : ");
             scanf("%d",&c);
             if(c==1){
                ptr->next=head;
                head=ptr;
             }
             else if(c==2){
                int no;
                printf("\nEnter ID after which you want to add a new student record : ");
                scanf("%d",&no);
                for(temp=head;(temp);temp=temp->next)
                {
                    if(temp->id==no)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                    }
                }
             }
             else{
                for(temp=head;(temp);temp=temp->next)
                {
                    prev=temp;
                }
                prev->next=ptr;
                ptr->next=NULL;
             }
        }
        printf("\nNew Student Added\n");
    }
}

void deleteAStudent(){

    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr,*prev;
        int sid,ans=0;
        printf("\nEnter Student ID to delete : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)
            {
                if(ptr==head)
                    head=head->next;
                else if(ptr->next==NULL)
                    prev->next=NULL;
                else
                    prev->next=ptr->next;
                free(ptr);
                printf("\nStudent ID Deleted!\n");
                ans=1;
                break;
            }
            prev=ptr;
        }
        if(ans==0)
            printf("\nStudent ID is not found!!\n");
    }
}

void searchAStudent(){
    if(head==NULL)
        printf("\nNo Students Found!\n");
    else{
        struct Student *ptr;
        int sid,ans=0;
        printf("\nEnter Student ID : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)
            {
                printf("\nID    %d",ptr->id);
                printf("\nName  %s",ptr->name);
                printf("\nAge   %d",ptr->age);
                printf("\nGrade %c",ptr->grade);
                printf("\n----------------------------");
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nStudent ID does not exist in the list.\n");
    }
}

void updateAStudent(){
    if(head==NULL)
        printf("\nNo Students Found!\n");
    else{
        struct Student *ptr;
        int sid,ans=0;
        printf("\nEnter Student ID : ");
        scanf("%d",&sid);
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            if(ptr->id==sid)//80
            {
                printf("\n-----------------------------------------");
                printf("\nEnter New Data -->\n");
                printf("\nEnter Age : ");
                scanf("%d",&ptr->age);
                fflush(stdin);
                printf("\nEnter Grade : ");
                scanf("%c",&ptr->grade);
                printf("\nStudent Details Updated!\n");
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nStudent ID is not found!\n");
    }
}

void displayAllRecords(){

    if(head==NULL)
        printf("\nNo Students Found!!\n");
    else{
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next)
        {
            printf("\nID    %d",ptr->id);
            printf("\nName  %s",ptr->name);
            printf("\nAge   %d",ptr->age);
            printf("\nGrade %c",ptr->grade);
            printf("\n----------------------------");
        }
    }
}

void countTotalStudents(){
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        int count=0;
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next){
            count++;
        }
        printf("\nTotal Records -> %d\n",count);
    }
}

void findMinAndMaxAge(){
    if(head==NULL)
        printf("\nNo Students Found!\n");
    else{
        struct Student *ptr;
        int minAge,maxAge;
        minAge=head->age;
        maxAge=head->age;
        for(ptr=head;(ptr);ptr=ptr->next){
            if(minAge>ptr->age)
                minAge=ptr->age;
            if(maxAge<ptr->age)
                maxAge=ptr->age;
        }
        printf("\nMinimum age Student is -> %d",minAge);
        printf("\nMaximum age Student is -> %d",maxAge);
    }

}

void main()
{
    head=NULL;
    int c;
    do{
        printf("\n1. Insert a Record");
        printf("\n2. Delete a Record");
        printf("\n3. Search For a Record");
        printf("\n4. Update a Record");
        printf("\n5. Display All Records");
        printf("\n6. Count Total Records");
        printf("\n7. Find Minimum and Maximum Age");
        printf("\n8. Exit");
        printf("\nSelect your Choice : ");
        scanf("%d",&c);
        if(c==1)
            addNewStudent();
        else if(c==2)
            deleteAStudent();
        else if(c==3)
            searchAStudent();
        else if(c==4)
            updateAStudent();
        else if(c==5)
            displayAllRecords();
        else if(c==6)
            countTotalStudents();
        else if(c==7)
            findMinAndMaxAge();
    }while(c!=8);
}
