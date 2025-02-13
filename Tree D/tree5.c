#include<stdio.h>
#include<stdlib.h>
struct Person{
    int data;
    struct Person *left,*right;
}*root;
struct Person *search(struct Person *p,int data)
{
    struct Person *parent;
    while(p!=NULL)
    {
        if(p->data==data)
        {
            return NULL;
        }
        else if(p->data>data)
        {
            parent=p;
            p=p->left;
        }
        else{
            parent=p;
            p=p->right;
        }
    }
    return parent;
}
void addNode()
{
    struct Person *ptr,*parent;
    ptr=(struct Person*)malloc(sizeof(struct Person));
    if(ptr==NULL)
        printf("\nCannot allocate memory!");
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
                printf("\nDuplicate value");
            else{
                if(parent->data>ptr->data)
                    parent->left=ptr;
                else
                    parent->right=ptr;
                ptr->left=ptr->right=NULL;
            }
        }
    }
}
void traversePre(struct Person *p)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(p==NULL)
        return;
    printf("\nData is %d",p->data);
    traversePre(p->left);
    traversePre(p->right);
}
void traverseIn(struct Person *p)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(p==NULL)
        return;
    traverseIn(p->left);
    printf("\nData is %d",p->data);
    traverseIn(p->right);
}
void traversePost(struct Person *p)
{
    if(root==NULL)
    {
        printf("\nTree is Empty!!\n");
        return;
    }
    if(p==NULL)
        return;
    traversePost(p->left);
    traversePost(p->right);
    printf("\nData is %d",p->data);
}
struct Person *delNode(struct Person *r,int data)
{
    struct Person *prev,*r1,*r2;
    if(r->data==data)
    {
        if(r->left==r->right)
            return NULL;
        else if(r->left==NULL)
            return r->right;
        else if(r->right==NULL)
            return r->left;
        else{
            r1=r2=r->right;
            while(r1->left!=NULL)
                r1=r1->left;
            r1->left=r->left;
            return r2;
        }
    }
    else if(r->data>data)
    {
        r->left=delNode(r->left,data);
    }
    else{
        r->right=delNode(r->right,data);
    }
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Person");
        printf("\n2. Traverse Pre Order");
        printf("\n3. Traverse In Order");
        printf("\n4. Traverse Post Order");
        printf("\n5. Delete Person");
        printf("\n6. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addNode();
        else if(c==2)
            traversePre(root);
        else if(c==3)
            traverseIn(root);
        else if(c==4)
            traversePost(root);
        else if(c==5)
        {
            if(root==NULL)
                printf("\nTree is Empty!!\n");
            else{
                int no;
                printf("\nEnter Data to delete : ");
                scanf("%d",&no);
                root=delNode(root,no);
            }
        }
    }while(c!=6);
}
