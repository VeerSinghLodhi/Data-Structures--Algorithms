#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Student{
    int rollno,age;
    char name[20],grade;
    struct Student *next;
}*head;
void add(){
    struct Student *ptr,*temp;
    int mess=1,size,isValid=1;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Roll no. : ");
        scanf("%d",&ptr->rollno);
        while(ptr->rollno<=0){
            printf("\nInvalid Roll no. !!");
            printf("\nPlease Enter Valid Student Roll no. : ");
            scanf("%d",&ptr->rollno);
        }
        if(head!=NULL){
            temp=head;
            do{
                while(temp->rollno==ptr->rollno)
                {
                    printf("\nStudent Roll no. already exist in the list");
                    printf("\nPlease enter unique roll no. : ");
                    scanf("%d",&ptr->rollno);
                    temp=head;// checking for Starting
                    while(ptr->rollno<=0){
                    printf("\nInvalid Roll no. !!");
                    printf("\nPlease Enter Valid Student Roll no. : ");
                    scanf("%d",&ptr->rollno);
                    }
                }
                temp=temp->next;
            }while(temp!=head);
        }
        printf("\nEnter Name : ");
        scanf("%s",ptr->name);
        size=strlen(ptr->name);
        for(int i=0;i<size;i++){
            if(!((ptr->name[i]>=65 && ptr->name[i]<=90) || (ptr->name[i]>=97 && ptr->name[i]<=122))){
                isValid=0;
                break;
            }
        }
        while(isValid==0){
            printf("\nInvalid Name!!");
            printf("\nPlease Enter Valid Name : ");//veersingh
            scanf("%s",&ptr->name);
            size=strlen(ptr->name);
            int res=1;
            for(int i=0;i<size;i++){
                if(!s((ptr->name[i]>='A' && ptr->name[i]<='Z') || (ptr->name[i]>='a' && ptr->name[i]<='z'))){
                    res=0;
                    break;
                }
            }
            if(res==1)
                isValid=1;
            else
                isValid=0;

        }
        printf("\nEnter Student Age : ");
        scanf("%d",&ptr->age);
        while(ptr->age<=0)
        {
            printf("\nInvalid Age!!");
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
            printf("\nPlease Enter Valid Grade : ");
            scanf("%c",&ptr->grade);
        }
        if(head==NULL){
            head=ptr;
            ptr->next=head;
        }
        else{
            int c;
            printf("\nWhere do you want insert?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1){
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                ptr->next=head;
                head=ptr;
                temp->next=head;
            }
            else if(c==2){
                int no,ans=0;
                printf("\nEnter Roll no. after which you want to insert new Student Record : ");
                scanf("%d",&no);
                temp=head;
                do{
                    if(temp->rollno==no){
                        ptr->next=temp->next;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0){
                    printf("\nStudent Roll no. is not found!!\n");
                    mess=0;
                }
            }
            else{
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                temp->next=ptr;
                ptr->next=head;
            }
        }
        if(mess==1)
            printf("\nNew Student Record Added!!\n");
    }
}
void traverse(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nRoll no. is %d",ptr->rollno);
            printf("\nName is %s",ptr->name);
            printf("\nAge is %d",ptr->age);
            printf("\nGrade is %c",ptr->grade);
            printf("\n----------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void search(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        int no,ans=0;
        struct Student *ptr;
        printf("\nEnter Roll no. to search : ");
        scanf("%d",&no);
        ptr=head;
        do{
            if(ptr->rollno==no){
                printf("\nStudent Details are :->");
                printf("\nRoll no. is %d",ptr->rollno);
                printf("\nName is %s",ptr->name);
                printf("\nAge is %d",ptr->age);
                printf("\nGrade is %c",ptr->grade);
                printf("\n----------------------");
                ans=1;
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nStudent Roll no. is not found!!\n");
    }
}
void del(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        if(head==head->next)
            printf("\nCan not delete!!");
        else{
            int no,ans=0;
            struct Student *ptr,*temp,*prev;
            printf("\nEnter Roll no. to delete : ");
            scanf("%d",&no);
            ptr=head;
            do{
                if(ptr->rollno==no){
                    if(ptr==head){
                        temp=head;
                        while(temp->next!=head)
                            temp=temp->next;
                        head=head->next;
                        temp->next=head;
                    }
                    else if(ptr->next==head){
                        prev->next=head;
                    }
                    else{
                        temp=head;
                        while(temp->next!=head)
                            temp=temp->next;
                        prev->next=ptr->next;
                    }
                    free(ptr);
                    printf("\nStudent Detail Deleted!!\n");
                    ans=1;
                    break;
                }
                prev=ptr;
                ptr=ptr->next;
            }while(ptr!=head);
            if(ans==0)
                printf("\nStudent Roll no. is not found!!\n");
        }
    }
}
void update(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        int no,ans=0,size,isValid=1;
        struct Student *ptr;
        printf("\nEnter Roll no. to update : ");
        scanf("%d",&no);
        ptr=head;
        do{
            if(ptr->rollno==no){
                printf("\nStudent Details are :->");
                printf("\nRoll no. is %d",ptr->rollno);
                printf("\nName is %s",ptr->name);
                printf("\nAge is %d",ptr->age);
                printf("\nGrade is %c",ptr->grade);
                printf("\n----------------------");
                printf("\nWhat do you want to update?");
                printf("\n1. Name");
                printf("\n2. Age");
                printf("\n3. Grade");
                printf("\n4. All");
                int c;
                printf("\nSelect a choice : ");
                scanf("%d",&c);
                if(c==1)
                {
                    printf("\nEnter  New Name : ");
                    scanf("%s",&ptr->name);
                    size=strlen(ptr->name);
                    for(int i=0;i<size;i++){
                        if(!((ptr->name[i]>=65 && ptr->name[i]<=90) || (ptr->name[i]>=97 && ptr->name[i]<=122))){
                            isValid=0;
                            break;
                        }
                    }
                    while(isValid==0){
                        printf("\nInvalid Name!!");
                        printf("\nPlease Enter Valid Name : ");//veersingh
                        scanf("%s",&ptr->name);
                        size=strlen(ptr->name);
                        int res=1;
                        for(int i=0;i<size;i++){
                            if(!((ptr->name[i]>='A' && ptr->name[i]<='Z') || (ptr->name[i]>='a' && ptr->name[i]<='z'))){
                                res=0;
                                break;
                            }
                        }
                        if(res==1)
                            isValid=1;
                        else
                            isValid=0;

                    }
                }
                else if(c==2)
                {
                    printf("\nEnter New Age : ");
                    scanf("%d",&ptr->age);
                    while(ptr->age<=0)
                    {
                        printf("\nInvalid Age!!");
                        printf("\nPlease Enter valid age : ");
                        scanf("%d",&ptr->age);
                    }

                }
                else if(c==3)
                {
                    fflush(stdin);
                    printf("\nEnter New Grade : ");
                    scanf("%c",&ptr->grade);
                    while(!(ptr->grade>='A' && ptr->grade<='F'))
                    {
                        printf("\nInvalid Grade!!");
                        fflush(stdin);
                        printf("\nPlease Valid Grade : ");
                        scanf("%c",&ptr->grade);
                    }
                }
                else if(c==4)
                {
                    printf("\nEnter New Name : ");
                    scanf("%s",ptr->name);
                    size=strlen(ptr->name);
                    for(int i=0;i<size;i++){
                        if(!((ptr->name[i]>=65 && ptr->name[i]<=90) || (ptr->name[i]>=97 && ptr->name[i]<=122))){
                            isValid=0;
                            break;
                        }
                    }
                    while(isValid==0){
                        printf("\nInvalid Name!!");
                        printf("\nPlease Enter New Valid Name : ");//veersingh
                        scanf("%s",&ptr->name);
                        size=strlen(ptr->name);
                        int res=1;
                        for(int i=0;i<size;i++){
                            if(!((ptr->name[i]>='A' && ptr->name[i]<='Z') || (ptr->name[i]>='a' && ptr->name[i]<='z'))){
                                res=0;
                                break;
                            }
                        }
                        if(res==1)
                            isValid=1;
                        else
                            isValid=0;

                    }
                    printf("\nEnter New Age : ");
                    scanf("%d",&ptr->age);
                    while(ptr->age<=0)
                    {
                        printf("\nInvalid Age!!");
                        printf("\nPlease Enter New valid age : ");
                        scanf("%d",&ptr->age);
                    }
                    fflush(stdin);
                    printf("\nEnter New Grade : ");
                    scanf("%c",&ptr->grade);
                    while(!(ptr->grade>='A' && ptr->grade<='F'))
                    {
                        printf("\nInvalid Grade!!");
                        fflush(stdin);
                        printf("\nPlease Enter new Valid Grade : ");
                        scanf("%c",&ptr->grade);
                    }
                }
                ans=1;
                printf("\nUpdated!!");
                break;
            }
            ptr=ptr->next;
        }while(ptr!=head);
        if(ans==0)
            printf("\nStudent Roll no. is not found!!\n");
    }
}
void getTotalRecords(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        int count=0;
        struct Student *ptr;
        ptr=head;
        do{
            count++;
            ptr=ptr->next;
        }while(ptr!=head);
        printf("\nTotal Record -> %d",count);
    }
}
void getMinAndMaxAge(){
    if(head==NULL)
        printf("\nNo Students Founds!!\n");
    else{
        int minAge,maxAge;
        minAge=head->age;
        maxAge=head->age;
        struct Student *ptr;
        ptr=head;
        do{
            if(minAge>ptr->age)
                minAge=ptr->age;
            if(maxAge<ptr->age)
                maxAge=ptr->age;
            ptr=ptr->next;
        }while(ptr!=head);
        printf("\nMinimum age Student %d",minAge);
        printf("\nMaximum age Student %d",maxAge);
    }
}
void getData()
{
    if(head==NULL)
        printf("\nNo Students Found!!");
    else{
        int frollno,lrollno;
        printf("\nFind Data between first to last roll no->");
        printf("\nEnter First Roll no : ");
        scanf("%d",&frollno);
        printf("\nEnter Last Roll no : ");
        scanf("%d",&lrollno);
        struct Student *ptr;
        ptr=head;
        do{
           if(ptr->rollno>=frollno || ptr->rollno>=lrollno)
           {
               printf("\nRoll no. is %d",ptr->rollno);
               printf("\nName is %s",ptr->name);
               printf("\nAge is %d",ptr->age);
               printf("\nGrade is %c",ptr->grade);
               printf("\n----------------------");
           }
           ptr=ptr->next;
        }while(ptr!=head);
    }
}
void main(){
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student ");
        printf("\n2. Traverse");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Update");
        printf("\n6. Total Records");
        printf("\n7. Min ans Max age");
        printf("\n8. Find data between 1 to n");
        printf("\n9. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse();
        else if(c==3)
            search();
        else if(c==4)
            del();
        else if(c==5)
            update();
        else if(c==6)
            getTotalRecords();
        else if(c==7)
            getMinAndMaxAge();
        else if(c==8)
            getData();
    }while(c!=9);
}
