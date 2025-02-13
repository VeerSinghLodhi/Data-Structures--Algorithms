#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int data;
    struct Student *left,*right;
}*root;
struct Student *search(struct Student *r,int data)
{
    struct Student *parent;
    while(r!=NULL)
    {
        if(r->data==data)
            return NULL;
        else if(r->data>data)
            return
    }
}
void addNode()
{
    struct Student *ptr;
    ptr=(struct Student*)malloc(sizeof(struct Studen));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter data : ");
        scanf("%d",&ptr->data);
        if(root==NULL)
        {
            root=ptr;
            ptr->left=ptr->right=NULL;
        }
        else{
            parent=search(root,ptr->data);
        }
    }
}

void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Pre");
        printf("\n3. In");
        printf("\n4. Post");
        printf("\n5. Delete Node");
        printf("\n6. Exit");
        printf("\nSelect a choice :");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            pre(root);
        else if(c==3)
            in(root);
        else if(c==4)
            post(root);
        else if(c==5)
        {
            if(root==NULL)
                printf("\nCannot allocate memory!!");
            else{
                int no;
                printf("\nEnter Data to delete");
                scanf("%d",&no);
                root=deleteElement(root,no);
            }
        }
    }while(c!=6);
}
