#include<stdio.h>
struct Product{
    int pno;
    char name[20];
    struct Product *next;
}*head;
void addNewProduct(){
    struct Product *ptr;
    ptr=(struct Product*)malloc(sizeof(struct Product));
    if(ptr==NULL){
        printf("\nCannot allocated memory!");
    }else{
        printf("\nEnter Product No. : ");
        scanf("%d",&ptr->pno);
        printf("\nEnter Product Name : ");
        scanf("%s",&ptr->name);
        if(head==NULL){
            head=ptr;
            ptr->next=NULL;
            printf("\nNew Student Added");
        }else{
            int c;
            printf("\nWhere do you want to insert?");
            printf("\n1. At the Beginning");
            printf("\n2. At the Middle");
            printf("\n3. At the End");
            printf("\nSelect a choice : ");
            scanf("%d",&c);
            if(c==1){
                ptr->next=head;
                head->next=ptr;
            }else if(c==2){
                int no,ans=0;
                printf("\nEnter Product no. after which you want to insert new record : ");
                scanf("%d",&no);
                struct Product *temp,*prev;
                for(temp=head;(temp);temp=temp->next){
                    if(temp->pno==no){
                        ptr->next=prev->next;
                        prev->next=ptr;
                        printf("\nNew Product Added");
                        ans=1;
                        break;
                    }
                    prev=temp;
                }
                if(ans==0){
                    printf("\nProduct no. does not exist!");
                }
            }else {
                struct Product *temp,*p;
                for(temp=head;(temp);temp=temp->next){
                    p=temp;
                }
                p->next=ptr;
                printf("\nNew Product Added");
            }
        }
    }
}

void showAllProducts(){

}

void delProduct(){

}
void main(){
    head=NULL;
    int ch;
    do{
        printf("\nLined List Option");
        printf("\n1. Add New Product");
        printf("\n2. Show All Products");
        printf("\n3. Delete a Product");
        printf("\n4. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&ch);
        if(ch==1){
            addNewProduct();
        }else if(ch==2){
            showAllProducts();
        }else if(ch==3){
            delProduct();
        }else if(ch==4){
            printf("\nExiting...");
        }else{
            printf("\nInvalid choice!");
        }
    }while(ch!=4);
}
