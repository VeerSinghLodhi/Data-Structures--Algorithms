#include<iostream>
#include<array>
using namespace std;
int main()
{
    array <int,6>myarr={1,2,3,4,5,6};
    cout<<" "<<myarr.at(0);
    cout<<" "<<myarr[1];

    cout<<"\nUsing Loop...";
    for(int i=0;i<myarr.size();i++)
    {
        cout<<" "<<myarr.at(i);
    }

}
