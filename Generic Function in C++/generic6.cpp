#include<iostream>
using namespace std;
template<class veer,class krishna,class rajendra>
class Person{
    veer srno;
    krishna name;
    rajendra age;
public:
    Person(veer srno,krishna name,rajendra age)
    {
        this->srno=srno;
        this->name=name;
        this->age=age;
    }
    void getPerson()
    {
        cout<<"\nSerial number is "<<srno;
        cout<<"\nName is "<<name;
        cout<<"\nAge is "<<age;
        cout<<"\n--------------------------------";
    }
};
int main()
{
    Person<int,string,int>person1(101,"Veer Singh Lodhi",19);
    person1.getPerson();

    Person<int,string,int>person2(102,"Krishna Kurmi",20);
    person2.getPerson();

    Person<int,string,int>person3(103,"Rajendra Kurmi",19);
    person3.getPerson();

    int srno,age;
    string name;
    cout<<"\nEnter Serial number : ";
    cin>>srno;
    cout<<"\nEnter Name : ";
    cin>>name;
    fflush(stdin);
    cout<<"\nEnter Age : ";
    cin>>age;
    Person<int,string,int>person4(srno,name,age);
    person4.getPerson();
}
