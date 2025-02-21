#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,string>players={{7,"MS-Dhoni"},{18,"Virat"},{45,"Rohit"}};
    for(auto i:players)
        cout<<"\n"<<i.first<<","<<i.second;

    cout<<"\nAfter Using Lower Bound Method"<<endl;
    auto it=players.lower_bound(19);//<=
    cout<<"\n"<<it->first<<", "<<it->second;

    cout<<"\nAfter Using Upper Bound Method"<<endl;
    it=players.upper_bound(6);//<
    cout<<"\n"<<it->first<<", "<<it->second;



}
