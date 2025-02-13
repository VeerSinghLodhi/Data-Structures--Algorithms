#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int rollno;
    char name[30];
    struct Student *left,*right;
}*root;
struct Student *search(struct Student *s,int data)
{
    struct Student *parent;
    while(s!=NULL)
    {
        if(s->rollno==data)
            return NULL;
        else if(s->rollno>data)
        {
            parent=s;
            s=s->left;
        }
        else{
            parent=s;
            s=s->right;
        }
    }
    return parent;
}
void addStudent()
{
    struct Student *ptr,*parent;
    ptr=(struct Student*)malloc(sizeof(struct Student));
    if(ptr==NULL)
        printf("\nCannot allocate memory!!");
    else{
        printf("\nEnter Roll no : ");
        scanf("%d",&ptr->rollno);
        printf("\nEnter Student Name : ");
        scanf("%s",&ptr->name);
        if(root==NULL)
        {
            root=ptr;
            ptr->left=ptr->right=NULL;
        }
        else{
            parent=search(root,ptr->rollno);
            if(parent==NULL)
                return;
            else{
                if(parent->rollno>ptr->rollno)
                    parent->left=ptr;
                else
                    parent->right=ptr;
                ptr->left=ptr->right=NULL;
            }
        }
        printf("\nNew Student Added");
    }
}
void getPrintf(struct Student *s)
{
    printf("\nRoll no is %d",s->rollno);
    printf("\nStudent Name %s",s->name);
    printf("\n---------------------------------");
}
void traverseInOrder(struct Student *s)
{
    if(s==NULL)
        return;
    traverseInOrder(s->left);
    getPrintf(s);
    traverseInOrder(s->right);
}
void traversePreOrder(struct Student *s)
{
    if(s==NULL)
        return;
    getPrintf(s);
    traversePreOrder(s->left);
    traversePreOrder(s->right);
}
void traversePostOrder(struct Student *s)
{
    if(s==NULL)
       return;
    traversePostOrder(s->left);
    traversePostOrder(s->right);
    getPrintf(s);
}
void main()
{
    root=NULL;
    int c;
    do{
        printf("\n1. Add new Student");
        printf("\n2. Traverse --> In Order");
        printf("\n3. Traverse --> Pre Order");
        printf("\n4. Traverse --> Post Order");
        printf("\n5. Exit");
        printf("\nSelect a choice : ");
        scanf("%d",&c);
        if(c==1)
            addStudent();
        else if(c==2)
            traverseInOrder(root);
        else if(c==3)
            traversePreOrder(root);
        else if(c==4)
            traversePostOrder(root);
    }while(c!=5);
}
