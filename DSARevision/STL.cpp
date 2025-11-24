#include<iostream>
#include<queue>
#include<stack>  // Done
#include<vector>  // Done
#include<list>// Done
#include<set>// Done
#include<unordered_set>  // Done
#include<unordered_map>  // Done
#include<map>  // Done
using namespace std;
int main(){
    // STL
    list<int>numbers;
    list<int>numbers2={1,2,3,4,5,6,7,8,9,10};

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);
    numbers.push_back(60);
    cout<<"\nSize of List is "<<numbers.size()<<endl;
    for(int srno : numbers){
        cout<<"Number is "<<srno<<endl;
    }
    cout<<"\n------------------------------"<<endl;

    cout<<"\nSize of Second List "<<numbers2.size()<<endl;

    vector<list<string>>vec(10);
    vec[0].push_back("Veer");
    vec[1].push_back("Krishna");
    vec[2].push_back("Rajedra");
    vec[3].push_back("Pawan");
    vec[4].push_back("Hani");

    cout<<"\nSize of vector is "<<vec.size()<<endl;

    cout<<"\nValues of vector are :"<<endl;

    for(list<string> a : vec){
        for(string str : a ){
            cout<<"Value is "<<str<<endl;
        }
    }

    cout<<"\n------------------------------"<<endl;

    set<int>setVar;
    setVar.insert(10);
    setVar.insert(20);
    setVar.insert(30);
    setVar.insert(10);
    setVar.insert(10);
    setVar.insert(10);
    cout<<"\nSize of set is "<<setVar.size()<<endl;

    unordered_set<int>us;
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(40);
    us.insert(10);

    cout<<"\nSize of Unordered Set is "<<us.size()<<endl;
    cout<<"\nUnordered Set values are : "<<endl;
    for(int val : us){
        cout<<"Value is "<<val<<endl;
    }

    unordered_map<int,string>unorder_map;

    unorder_map[1]="Veer";
    unorder_map[2]="Krishna";
    unorder_map[3]="Rajendra";
    unorder_map[4]="Ayush";

    for(auto it=unorder_map.begin();it!=unorder_map.end();it++){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
    }

    map<int,string>ordered_map;
    ordered_map[1]="Damoh";
    ordered_map[2]="Sagar";
    ordered_map[3]="Indore";
    ordered_map[4]="Bhopal";

    cout<<"\nSize of Ordered Map is "<<ordered_map.size()<<endl;

    cout<<"\nOrder Map values are : "<<endl;
    for(auto it=ordered_map.begin();it!=ordered_map.end();it++){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        cout<<"-------------------------------------"<<endl;
    }

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.pop();

    cout<<"\nSize of Stack is "<<s.size()<<endl;

    cout<<"Values of stack are : "<<endl;
    cout<<"\nTop value is "<<s.top()<<endl;
    stack<int>s2;
    while(!s.empty())
    {
        cout<<"\nValue is "<<s.top()<<endl;
        s2.push(s.top());
        s.pop();
    }
    s=s2;
    cout<<"\nSize of Stack is "<<s.size()<<endl;


    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    cout<<"\nQueue Front is "<<q.front()<<endl;
    cout<<"\nQueue values are : "<<endl;

    while(!q.empty()){
        cout<<"Value is "<<q.front()<<endl;
        q.pop();
    }



}
