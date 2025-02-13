#include<stdio.h>
#include<stdlib.h>
struct Student{
    int data;
    struct Student *next;
}*head;
void addStudent(){
    struct Student *ptr,*temp;
    int v=1;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(head==NULL){
            head=ptr;
            head->next=head;
        }
        else{
            int c;
            printf("\nWhere do you want insert?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Specific Position");
            printf("\n3. At the End");
            printf("\nEnter a choice : ");
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
                int v,ans=0;
                printf("\nEnter data after which you want to insert new record : ");
                scanf("%d",&v);
                temp=head;
                do{
                    if(temp->data==v)
                    {
                        ptr->next=temp->next;
                        temp->next=ptr;
                        ans=1;
                        break;
                    }
                    temp=temp->next;
                }while(temp!=head);
                if(ans==0){
                    printf("\nData is not found!!");
                    return;
                }
            }
            else if(c==3){
                temp=head;
                while(temp->next!=head)
                    temp=temp->next;
                temp->next=ptr;
                ptr->next=head;
            }
        }
        printf("\nNew Student Added");
    }
}
void traverse(){
    if(head==NULL)
        printf("\nNo Nodes found!!");
    else{
        struct Student *ptr;
        ptr=head;
        do{
            printf("\nData is %d",ptr->data);
            printf("\n----------------------");
            ptr=ptr->next;
        }while(ptr!=head);
    }
}
void delStudent(){
    if(head==NULL)
        printf("\nNo Nodes Found!!");
    else{
        struct Student *temp,*v,*prev;
        int c,ans=0;
        printf("\nEnter data to delete : ");
        scanf("%d",&c);
        temp=head;
        do{
            if(temp->data==c){
                if(temp==head){
                    if(head->next==head)
                        head=NULL;
                    else{
                        v=head;
                        while(v->next!=head)
                            v=v->next;
                        head=head->next;
                        v->next=head;
                    }
                }
                else if(temp->next==head){
                    prev->next=head;
                }
                else{
                    prev->next=temp->next;
                }
                ans=1;
                free(temp);
                printf("\nDeleted!!");
                break;
            }
            prev=temp;
            temp=temp->next;
        }while(temp!=head);
        if(ans==0)
            printf("\nData is not found!!");
    }
}
void main(){
    head=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse");
        printf("\n3. Delete");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addStudent();
        else if(c==2)
            traverse();
        else if(c==3)
            delStudent();
    }while(c!=4);
}
