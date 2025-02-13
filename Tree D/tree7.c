#include<stdio.h>
#include<stdlib.h>
struct BankAccount
{
    int data;
    struct BankAccount *left,*right;
}*root;
struct BankAccount *search(struct BankAccount *b,int data)
{
    struct BankAccount *parent;
    while(b!=NULL)
    {
        if(b->data==data)
            return NULL;
        else if(b->data>data)
        {
            parent=b;
            b=b->left;
        }
        else{
            parent=b;
            b=b->right;
        }
    }
    return parent;
}
void addNode()
{
    struct BankAccount *ptr,*parent;
    ptr=(struct BankAccount*)malloc(sizeof(struct BankAccount));
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
            if(parent==NULL){
                printf("\nDuplicate value");
                return;
            }
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
void preOrder(struct BankAccount *b)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(b==NULL)
        return;
    printf("\nData is %d",b->data);
    preOrder(b->left);
    preOrder(b->right);
}
void inOrder(struct BankAccount *b)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(b==NULL)
        return;
    preOrder(b->left);
    printf("\nData is %d",b->data);
    preOrder(b->right);
}
void postOrder(struct BankAccount *b)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(b==NULL)
        return;
    preOrder(b->left);
    preOrder(b->right);
    printf("\nData is %d",b->data);
}
struct BankAccount *deleteNode(struct BankAccount *b,int data)
{
    struct BankAccount *prev,*r1;
    if(b->data==data)
    {
        if(b->left==b->right)
            prev=NULL;
        else if(b->left==NULL)
            prev=b->right;
        else if(b->right==NULL)
            prev=b->left;
        else{
            r1=prev=b->left;
            while(r1->right!=NULL)
                r1=r1->right;
            r1->right=b->right;
        }
        free(b);
        return prev;
    }
    else if(b->data>data)
        b->left=deleteNode(b->left,data);
    else
        b->right=deleteNode(b->right,data);
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Node");
        printf("\n2. Pre Order");
        printf("\n3. In Order");
        printf("\n4. Post Order");
        printf("\n5. Delete Node");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            preOrder(root);
        else if(c==3)
            inOrder(root);
        else if(c==4)
            postOrder(root);
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
