#include<iostream>
using namespace std;
template<class t>
void getChangeValues(t &v,t &m)
{
    t c;
    c=v;
    v=m;
    m=c;
}
int main()
{
    int a=10,b=20;
    cout<<"Before Swapping...."<<endl;
    cout<<"A is "<<a<<endl;
    cout<<"B is "<<b<<endl;
    cout<<"After Swapping...."<<endl;
    getChangeValues(a,b);
    cout<<"A is "<<a<<endl;
    cout<<"B is "<<b<<endl;
}
