#include<stdio.h>
#include<stdlib.h>
struct Person{
    int data;
    struct Person *prev,*next;
}*head,*end;
void addPerson(){
    struct Person *ptr;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        if(head==NULL){
            head=end=ptr;
            ptr->prev=end;
            ptr->next=head;
        }
        else{
            end->next=ptr;
            ptr->prev=end;
            end=ptr;
            end->next=head;
            head->prev=end;
        }
        printf("\nNew Person Added");
    }
}
void traverseHeadToEnd(){
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Person *temp;
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
        printf("\nNo Nodes Found!!");
    else{
        struct Person *temp;
        temp=end;
        do{
            printf("\nData is %d",temp->data);
            printf("\n-----------------------");
            temp=temp->prev;
        }while(temp!=end);
    }
}
void deletePerson(){
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        int c,ans=0;
        struct Person *temp;
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
            printf("\nData is not found!!");
    }
}
void main(){
    head=end=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse (Head to End)");
        printf("\n3. Traverse (End to Head)");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addPerson();
        else if(c==2)
            traverseHeadToEnd();
        else if(c==3)
            traverseEndToHead();
        else if(c==4)
            deletePerson();
    }while(c!=5);
}
