#include<iostream>
#include<list>
using namespace std;
int main()
{
    list<int>li;
    for(int i=1;i<=10;i++)
        li.push_back(i);
    li.pop_back();

    for(auto i:li)
        cout<<"\n"<<i;
}
