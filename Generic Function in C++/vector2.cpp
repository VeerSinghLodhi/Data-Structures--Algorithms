#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>vec1={1,2,3,4,5,6,7};
    vector<int>::iterator v;
    vec1.push_back(8);
    auto i=vec1.begin();
    cout<<"\nFirst Values "<<*i;
    i=vec1.end()-1;
    cout<<"\nLast Values "<<*i;

    for(v=vec1.begin();v!=vec1.end();v++)
        cout<<"\n "<<*v;
}
