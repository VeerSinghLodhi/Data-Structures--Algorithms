#include<stdio.h>
#include<stdlib.h>
struct Student{
    int rollno;
    char name[30];
    struct Student *prev,*next;
}*head,*end;
void addNode(){
    struct Student *ptr,*temp;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        int ans=0;
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
        printf("\nEnter Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL){
            head=end=ptr;
            head->prev=NULL;
            end->next=NULL;
            ans=1;
        }
        else{
            int c;
            printf("\nWhere do you want insert?");
            printf("\n1. At the Begging");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice :");
            scanf("%d",&c);
            if(c==1){
                ptr->next=head;
                head->prev=ptr;
                head=ptr;
                head->prev=NULL;
                ans=1;
            }
            else if(c==2){
                int v;
                printf("\nEnter Roll no after which you want insert new record : ");
                scanf("%d",&v);
                for(temp=head;(temp);temp=temp->next){
                    if(temp->rollno==v)
                    {
                        ptr->prev=temp;
                        ptr->next=temp->next;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                }
                if(ans==0)
                    printf("\nRoll no is not found!!");
            }
            else if(c==3){
                end->next=ptr;
                ptr->prev=end;
                end=ptr;
                end->next=NULL;
                ans=1;
            }
        }
        if(ans!=0)
            printf("\nNew Student Added");
    }
}
void traverseHeadToEnd()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        struct Student *temp;
        for(temp=head;(temp);temp=temp->next){
            printf("\nRoll no is %d",temp->rollno);
            printf("\nName is %s",temp->name);
            printf("\n----------------------");
        }
    }
}
void traverseEndToHead()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        struct Student *temp;
        for(temp=end;(temp);temp=temp->prev){
            printf("\nRoll no is %d",temp->rollno);
            printf("\nName is %s",temp->name);
            printf("\n----------------------");
        }
    }
}
void deleteNode()
{
    if(head==NULL)
        printf("\nLink List is empty!!");
    else{
        int d,ans=0;
        printf("\nEnter Roll no to delete : ");
        scanf("%d",&d);
        struct Student *ptr;
        for(ptr=head;(ptr);ptr=ptr->next){
            if(ptr->rollno==d)
            {
                if(ptr==head){
                    if(head->next==NULL)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=NULL;
                    }
                }
                else if(ptr==end){
                    end=end->prev;
                    end->next=NULL;
                }
                else{
                    ptr->next->prev=ptr->prev;
                    ptr->prev->next=ptr->next;
                }
                free(ptr);
                printf("\nStudent Deleted");
                ans=1;
                break;
            }
        }
        if(ans==0)
            printf("\nRoll no is not found!!");
    }
}
void main(){
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse(Head to End)");
        printf("\n3. Traverse(End to Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect a choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
                addNode();
                break;
            case 2:
                traverseHeadToEnd();
                break;
            case 3:
                traverseEndToHead();
                break;
            case 4:
                deleteNode();
                break;
        }
    }while(c!=5);
}
