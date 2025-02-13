#include<iostream>
using namespace std;
template<class t,class t1>
void sum(t v,t1 m)
{
    t s;
    s=v+m;
    cout<<"\nSum is "<<s<<endl;
}
int main()
{
    sum(10,10);
    sum(14.5,15.5);
   // sum("veer","singh");
}
