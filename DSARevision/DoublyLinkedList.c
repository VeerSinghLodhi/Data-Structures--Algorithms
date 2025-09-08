#include<stdio.h>
struct Student{
    int srno;
    char name[20];
    struct Student *prev,*next;
}*head,*end;
void addNewStudent(){
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL){
        printf("\nMemory cannot allocated!");
    }else{
        printf("\nEnter Serial number : ");
        scanf("%d",&ptr->srno);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL){
            head=end=ptr;
            head->prev=NULL;
            end->next=NULL;
            printf("\nNew Student Added");
        }else{






        }
    }
}
void showAllStudent(){

}
void main(){
    int ch;
    do{
        printf("\nOptions");
        printf("\n1. Add New Student");
        printf("\n2. Show All Students");
        printf("\n3. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&ch);
        if(ch==1){
            addNewStudent();
        }else if(ch==2){
            showAllStudent();
        }else if(ch==3){
            printf("\nExiting...");
        }else{
            printf("\nInvalid Choice!");
        }
    }while(ch!=3);
}
