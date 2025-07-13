#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<set>
#include<unordered_set>
using namespace std;
int main(){
    vector<int>vec1={1,2,3,4,5,6};
    cout<<vec1.at(0)<<endl;
    cout<<*vec1.begin()<<endl;
    cout<<*vec1.begin()+1;
    cout<<"\n----------------"<<endl;
    for(auto it=vec1.begin();it!=vec1.end();it++){
        cout<<*it<<" " ;
    }
    cout<<"\nReverse Printing.."<<endl;
    for(auto it=vec1.rbegin();it!=vec1.rend();it++){
        cout<<*it<<" " ;
    }
    cout<<"\nUnorder map"<<endl;
    unordered_map<int,bool>ump={{1,true},{2,false}};
//    cout<<;
    if(ump.find(1)==ump.end()){
        cout<<"Find!";
    }
    cout<<"\nSet STL"<<endl;

    set<int>s1={1,2,3};
    /*for(auto it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    s1.insert(2);// Not Allow
    for(auto it=s1.begin();it!=s1.end();it++){
        cout<<*it<<" ";
    }*/

    cout<<endl;
    unordered_set<int>visited;
    visited.insert(1);
    for(auto it=visited.begin();it!=visited.end();it++){
        cout<<*it<<" ";
    }
    if(visited.find(1)==visited.end()){
        cout<<"\nFound!!";
    }
    else{
        cout<<"\nNot Found!";
    }

    return 0;
}
