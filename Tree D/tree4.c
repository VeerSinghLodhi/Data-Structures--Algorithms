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
        {
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
void addNode()
{
    struct Student *ptr,*parent;
    ptr=(struct Student*)malloc(sizeof(struct Student));
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
            {
                printf("\nDuplicate value");
            }
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
void traversePre(struct Student *r)
{
    if(r==NULL)
        return;
    printf("\nData is %d",r->data);
    traversePre(r->left);
    traversePre(r->right);

}
void traverseIn(struct Student *r)
{
    if(r==NULL)
        return;
    traverseIn(r->left);
    printf("\nData is %d",r->data);
    traverseIn(r->right);
}
void traversePost(struct Student *r)
{
    if(r==NULL)
        return;
    traversePost(r->left);
    traversePost(r->right);
    printf("\nData is %d",r->data);
}
struct Student *delElement(struct Student *r,int data)
{
    struct Student *prev,*r1,*r2;
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
        r->left=delElement(r->left,data);
    }
    else{
        r->right=delElement(r->right,data);
    }
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse( Pre Order )");
        printf("\n3. Traverse( In Order");
        printf("\n4. Traverse( Post Order)");
        printf("\n5. Delete");
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
        else if(c==5){
            if(root==NULL)
                printf("\nCannot delete");
            else{
                int no;
                printf("\nEnter data to delete : ");
                scanf("%d",&no);
                root=delElement(root,no);
            }
        }
    }while(c!=6);
}
