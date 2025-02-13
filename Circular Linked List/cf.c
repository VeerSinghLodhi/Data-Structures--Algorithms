#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
    char name[20];
    int ans=1;
    printf("\nEnter a String : ");
    scanf("%s",&name);
    int size=strlen(name);
    printf("\nSize is %d",size);
    for(int i=0;i<size;i++)
    {
        char ch=name[i];
        if(!(ch>=65 && ch<=90 || ch>=97 && ch<=122 || isspace(ch)))
            ans=0;

    }
    if(ans==0)
        printf("\nInvalid Name!!");
    else if(ans==1)
        printf("\nValid Name!!");

}
