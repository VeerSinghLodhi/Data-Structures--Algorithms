#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string ,int>cities={{"Sagar",2},{"Bhopal",3},{"Jabalpur",4}};

    int pop=cities["Sagar"];//This operator method. if the element does not exist in the map then this method add new element with the value 0;
    cout<<"\nPopulation of Sagar is "<<pop<<" Lakhs";

    pop=cities.at("Bhopal");//This at method only show data if the element exist in the map
    cout<<"\nPopulation of Bhopal is "<<pop<<" Lakhs";

    //Using Iterator
    unordered_map<string,int>::iterator it=cities.find("Jabalpur");
    cout<<"\nPopulation of Jabalput is "<<it->second<<" Lakhs";

    cout<<"\n\nPRINTING COMPLETE MAP";
    cout<<"\nMethod 1\n";
    //Using auto
    for(auto a:cities)
        cout<<"\n"<<a.first<<","<<a.second;
    /* unordered_map<string ,int>cities;
                        |     |
                       Key   value
    first function for key. it means primary key. key=primary key
     second function for value.*/

    unordered_map<string,int>::iterator it1=cities.find("Sagar");
    if(it1!=cities.end()){
        cout<<"\nFound!!";
    }
    else{
        cout<<"\nNot Found!!";
    }

    //Add new element by the using of method
    cout<<"\n\nAfter Insert Damoh\n";
    cities.insert(make_pair("Damoh",1));
    for(auto i:cities)
        cout<<"\n"<<i.first<<","<<i.second;

    //Second Operator method to add the new element
    cities["Indore"]=3;
    cout<<"\n\nAfter Insert Indore\n";
    for(auto i:cities)
        cout<<"\n"<<i.first<<","<<i.second;

}
