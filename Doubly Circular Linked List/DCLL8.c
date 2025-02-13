#include<stdio.h>
#include<stdlib.h>
struct Student{
    int data;
    struct Student *prev,*next;
}*head,*end;
void addStudent(){
    struct Student *ptr,*temp;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL){
            head=end=ptr;
            ptr->prev=end;
            ptr->next=head;
        }
        else{
            int c,ans=0;
            printf("\nWhere do you want to insert?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1){
                head->prev=ptr;
                ptr->next=head;
                head=ptr;
                head->prev=end;
                end->next=head;
            }
            else if(c==2){
                int v;
                printf("\nEnter data after which you want insert new record : ");
                scanf("%d",&v);
                temp=head;
                do{
                    if(temp->data==v)
                    {
                        ptr->next=temp->next;
                        ptr->prev=temp;
                        temp->next->prev=ptr;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0){
                    printf("\nData is not found!!\n");
                    return;
                }
            }
            else if(c==3){
                end->next=ptr;
                ptr->prev=end;
                end=ptr;
                end->next=head;
                head->prev=end;
            }
        }
        printf("\nNew Student Added\n");
    }
}
void traverseHeadToEnd(){
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *temp;
        temp=head;
        do{
            printf("\nData is %d",temp->data);
            printf("\n-----------------------");
            temp=temp->next;
        }while(temp!=head);
    }
}
void traverseEndToHead(){
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        struct Student *temp;
        temp=end;
        do{
            printf("\nData is %d",temp->data);
            printf("\n-----------------------");
            temp=temp->prev;
        }while(temp!=end);
    }
}
void deleteStudent(){
    if(head==NULL)
        printf("\nNo Nodes Found!!\n");
    else{
        int c,ans=0;
        struct Student *temp;
        printf("\nEnter data to delete : ");
        scanf("%d",&c);
        temp=head;
        do{
            if(temp->data==c){
                if(temp==head){
                    if(head->next==head)
                        head=end=NULL;
                    else{
                        head=head->next;
                        head->prev=end;
                        end->next=head;
                    }
                }
                else if(temp==end){
                    end=end->prev;
                    end->next=head;
                    head->prev=end;
                }
                else{
                    temp->next->prev=temp->prev;
                    temp->prev->next=temp->next;
                }
                ans=1;
                free(temp);
                printf("\nDeleted!!");
                break;
            }
            temp=temp->next;
        }while(temp!=head);
        if(ans==0)
            printf("\nData is not found!!\n");
    }
}
void main(){
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse (Head to End)");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addStudent();
        else if(c==2)
            traverseHeadToEnd();
        else if(c==3)
            traverseEndToHead();
        else if(c==4)
            deleteStudent();
    }while(c!=5);
}
