#include<iostream>
#include<string>
using namespace std;
template<class t1,class t2>
class Student{
    t1 rollno;
    t2 name;
public:
    Student(t1 rollno,t2 name)
    {
        this->rollno=rollno;
        this->name=name;
    }
    void getStudent()
    {
        cout<<"\nStudent Roll no is "<<rollno;
        cout<<"\nName is "<<name;
    }
};
int main()
{
    Student<int,string>s1(101,"Veer Singh");
    s1.getStudent();

    Student<int,string>s2(102,"Muskan Shroti");
    s2.getStudent();

    return 0;
}
