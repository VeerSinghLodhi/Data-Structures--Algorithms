#include<stdio.h>
#include<stdlib.h>
struct Demo
{
    int data;
    struct Demo *left,*right;
}*root;
struct Demo *search(struct Demo *d,int data)
{
   struct Demo *parent;
   while(d!=NULL)
   {
       if(d->data==data)
        return NULL;
       else if(d->data>data)
       {
           parent=d;
           d=d->left;
       }
    else{
        parent=d;
        d=d->right;
    }
   }
   return parent;
}
void addNode()
{
    struct Demo *ptr,*parent;
    ptr=(struct Demo*)malloc(sizeof(struct Demo));
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
            if(parent==NULL)
                printf("\nDuplicate value");
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
void traversePreOrder(struct Demo *d)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(d==NULL)
        return;

    printf("\nData is %d",d->data);
    traversePreOrder(d->left);
    traversePreOrder(d->right);
}
void traverseInOrder(struct Demo *d)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(d==NULL)
        return;
    traverseInOrder(d->left);
    printf("\nData is %d",d->data);
    traverseInOrder(d->right);
}
void traversePostOrder(struct Demo *d)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(d==NULL)
        return;
    traversePostOrder(d->left);
    traversePostOrder(d->right);
    printf("\nData is %d",d->data);
}
struct Demo *deleteNode(struct Demo *d,int data)
{
    struct Demo *prev,*r1;
    if(d->data==data)
    {
        if(d->left==d->right){
            prev = NULL;
        }
        else if(d->left==NULL){
            prev = d->right;
        }
        else if(d->right==NULL){
            prev = d->left;
        }
        else{
            r1=prev=d->right;
            while(r1->left!=NULL)
                r1=r1->left;
            r1->left=d->left;
        }
        free(d);
        return prev;
    }
    else if(d->data>data)
    {
        d->left=deleteNode(d->left,data);
    }
    else{
        d->right=deleteNode(d->right,data);
    }
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Traverse Pre Order");
        printf("\n3. Traverse In Order");
        printf("\n4. Traverse Post Order");
        printf("\n5. Delete Node");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            traversePreOrder(root);
        else if(c==3)
            traverseInOrder(root);
        else if(c==4)
            traversePostOrder(root);
        else if(c==5)
        {
            if(root==NULL)
                printf("\nTree is Empty!!\n");
            else{
                int no;
                printf("\nEnter data to delete : ");
                scanf("%d",&no);
                root=deleteNode(root,no);
            }
        }
    }while(c!=6);
}
