#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int>v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(70);


    /*cout<<" "<<v1.at(0);
    cout<<" "<<v1[1];
    cout<<" "<<v1[0];*/
    cout<<"\nBy Using at function....";
    for(int i=0;i<v1.size();i++)
        cout<<" "<<v1.at(i);

    cout<<"\nBy Using Square Braces...";
    for(int i=0;i<v1.size();i++)
        cout<<" "<<v1[i];

     cout<<"\nBy Using Auto.....";
     for(auto i=v1.begin();i!=v1.end();i++)
            cout<<" "<<*i;

    int a;
    a=*v1.begin();
    cout<<"\nFirst Value: "<<a;

    auto b=v1.begin();
    cout<<"\nFirst Value : "<<*b;

}
