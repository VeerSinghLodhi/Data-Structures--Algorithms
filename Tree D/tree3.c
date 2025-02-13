#include<stdio.h>
#include<stdlib.h>
struct Tree{
    int data;
    struct Tree *left,*right;
}*root;
struct Tree *search(struct Tree *v,int data)
{
    struct Tree *parent;
    while(v!=NULL)
    {
        if(v->data==v)
            return NULL;
        else if(v->data>data)
        {
            parent=v;
            v=v->left;
        }
        else{
            parent=v;
            v=v->right;
        }
    }
    return parent;
}
void add()
{
    struct Tree *ptr,*parent;
    ptr=(struct Tree*)malloc(sizeof(struct Tree));
    printf("\nEnter data : ");
    scanf("%d",&ptr->data);
    if(root==NULL)
    {
        root=ptr;
        ptr->left=ptr->right=NULL;
    }
    else{
        parent=search(root,ptr->data);
        if(parent==NULL)
            printf("\nAlready Exist");
        else{
            if(parent->data>ptr->data)
            {
                parent->left=ptr;
            }
            else{
                parent->right=ptr;
            }
            ptr->left=ptr->right=NULL;
        }
    }
}
void traverse1(struct Tree *r)
{
    if(r==NULL)
        return;
    traverse1(r->left);
    printf("\nData is %d",r->data);
    traverse1(r->right);
}
void traverse2(struct Tree *r)
{

   if(r==NULL)
        return;

    printf("\nData is %d",r->data);
    traverse2(r->left);
    traverse2(r->right);
}
void traverse3(struct Tree *r)
{
    if(r==NULL)
        return;
    traverse3(r->left);
    traverse3(r->right);
    printf("\nData is %d",r->data);
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Traverse(In Order)");
        printf("\n3. Traverse(Pre Order)");
        printf("\n4. Traverse (Post Order)");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traverse1(root);
        else if(c==3)
            traverse2(root);
        else if(c==4)
            traverse3(root);
    }while(c!=5);
}
