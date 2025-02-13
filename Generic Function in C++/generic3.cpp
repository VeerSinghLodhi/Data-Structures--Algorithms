#include<iostream>
#include<string>
using namespace std;
template<class t,class t1>
class Student
{
    t rollno;
    t1 name;
public:
    void setData(t rollno,t1 name)
    {
        this->rollno=rollno;
        this->name=name;
    }
    void getData()
    {
        cout<<"\nRoll no "<<rollno;
        cout<<"\nName is "<<name;
    }
};
int main()
{
    Student <int,string>s1;
    s1.setData(101,"veer");
    s1.getData();
}
