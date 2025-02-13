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
        else {
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
        printf("\nCannot allocate memory!!");
    else {
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
                printf("\nDuplicate Value!!");
            else{
                if(parent->data>ptr->data)
                    parent->left=ptr;
                else
                    parent->right=ptr;
                ptr->left=ptr->right=NULL;
            }
        }
        printf("\nNew Data Added!!");
    }
}
void traversePre(struct Tree *p)
{
    if(p==NULL)
        return;
    printf("\n%d",p->data);
    traversePre(p->left);
    traversePre(p->right);
}
void traverseIn(struct Tree *i)
{
    if(i==NULL)
        return;
    traverseIn(i->left);
    printf("\n%d",i->data);
    traverseIn(i->right);
}
void traversePost(struct Tree *p)
{
    if(p==NULL)
        return;
    traversePost(p->left);
    traversePost(p->right);
    printf("\n%d",p->data);
}
struct Tree *deleteData(struct Tree *r,int data)
{
    struct Tree *r1,*r2;
    if(r->data==data)
    {
        if(r->left==r->right)
            return NULL;
        else if(r->left==NULL)
            return r->right;
        else if(r->right==NULL)
            return r->left;
        else {
            r1=r2=r->right;
            while(r1->left!=NULL)
                r1=r1->left;
            r1->left=r->left;
        }
    }
    else if(r->data>data)
    {
        r->left=deleteData(r->left,data);
    }
    else{
        r->right=deleteData(r->right,data);
    }

}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Data");
        printf("\n2. Traverse(Pre Order");
        printf("\n3. Traverse(In Order");
        printf("\n4. Traverse(Post Order");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            add();
        else if(c==2)
            traversePre(root);
        else if(c==3)
            traverseIn(root);
        else if(c==4)
            traversePost(root);
        else if(c==5)
        {
            if(root==NULL)
                printf("\nTree is empty!!");
            else{
                int c;
                printf("\nEnter data to delete : ");
                scanf("%d",&c);
                root=deleteData(root,c);
                printf("\nDeleted!!");
            }
        }
    }while(c!=6);
}
