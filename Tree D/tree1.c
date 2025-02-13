#include<stdio.h>
#include<stdlib.h>
struct Tree
{
    int data;
    struct Tree *left,*right;
}*root;
struct Tree *search(struct Tree *r,int data)
{
    struct Tree *parent;
    while(r!=NULL)
    {
        if(r->data==data)
            return NULL;
        else if(r->data>data){
            parent=r;
            r=r->left;
        }
        else{
            parent=r;
            r=r->right;
        }
    }
    return parent;
}
void add()
{
    struct Tree *ptr,*parent;
    ptr=(struct Tree*)malloc(sizeof(struct Tree));
    if(ptr==NULL)
    {
        printf("\nCannot allocate memory!!");
    }
    else{
        printf("\nEnter Data : ");
        scanf("%d",&ptr->data);
        if(root==NULL)
        {
            root=ptr;
            ptr->left=ptr->right=NULL;
        }
        else{
            parent=search(root,ptr->data);
            if(parent==NULL)
                printf("\nDuplicate Data");
            else{
                if(parent->data>ptr->data)
                    parent->left=ptr;
                else
                    parent->right=ptr;
                ptr->left=ptr->right=NULL;
            }
        }
        printf("\nNew Node Added");
    }
}
void traverse_InOrder(struct Tree *r)
{
    // LEFT --> ROOT --> RIGHT;
    if(r==NULL)
        return;
    traverse_InOrder(r->left);
    printf("\nData is %d",r->data);
    traverse_InOrder(r->right);
}
void traverse_PreOrder(struct Tree *r)
{
    //ROOT --> LEFT --> RIGHT;
    if(r==NULL)
        return;
    printf("\nData is %d",r->data);
    traverse_PreOrder(r->left);
    traverse_PreOrder(r->right);
}
void traverse_PostOrder(struct Tree *r)
{
    //LEFT --> RIGHT --> ROOT;
    if(r==NULL)
        return;
    traverse_PostOrder(r->left);
    traverse_PostOrder(r->right);
    printf("\nData is %d",r->data);
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Traverse -->  In-Order");
        printf("\n3. Traverse -->  Pre-Order");
        printf("\n4. Traverse -->  Post-Order");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse_InOrder(root);
        else if(c==3)
            traverse_PreOrder(root);
        else if(c==4)
            traverse_PostOrder(root);
    }while(c!=5);
}
