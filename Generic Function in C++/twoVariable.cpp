#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int &b=a;
    cout<<"A is "<<a<<endl;
    cout<<"======================"<<endl;
    b+=a;
    cout<<"A is "<<a<<endl;
    return 0;
}
