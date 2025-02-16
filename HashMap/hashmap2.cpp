#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Student{
    int rollno;
    string name;
    unordered_map<int,string>student;
public:
    void addStudent(int rollno,string name){
        this->rollno=rollno;
        this->name=name;
        student.insert(make_pair(this->rollno,this->name));
    }
    void getStudents(){
        for(auto i:student){
            cout<<"\nStudent Roll no. is "<<i.first<<" and name is "<<i.second;
            cout<<"\n-----------------------------------------";
        }
        cout<<endl;
    }
    bool getFindStudent(int rollno)
    {
        unordered_map<int,string>::iterator it=student.find(rollno);
        if(it!=student.end())
            return true;
        else
            return false;
    }
};
int main()
{
    Student student1;
    int c;
    do{
        cout<<"\n1. Add New Student";
        cout<<"\n2. Show All Students";
        cout<<"\n3. Search a Student";
        cout<<"\n4. Exit";
        cout<<"\nSelect a choice : ";
        cin>>c;
        if(c==1){
            int roll;
            string name;
            cout<<"\nEnter Student roll no. : ";
            cin>>roll;
            cout<<"\nEnter Student name : ";
            cin>>name;
            student1.addStudent(roll,name);
            fflush(stdin);
        }
        else if(c==2){
            student1.getStudents();
        }
        else if(c==3){
            bool ans;
            int no;
            cout<<"\nEnter Roll no. to find : ";
            cin>>no;
            ans=student1.getFindStudent(no);
            if(ans)
                cout<<"\nFound!!\n";
            else
                cout<<"\nNot Found!!\n";
        }
    }while(c!=4);




   /* student1.addStudent(101,"Krishna Kurmi");
    student1.addStudent(102,"Rajendra Kurmi");
    student1.addStudent(103,"Veer Singh");
    student1.addStudent(104,"Muskan Shroti");
    student1.getStudent();
    cout<<"\nFinding Student....";
    bool ans;
    ans=student1.getFindStudent(103);
    if(ans==true)
        cout<<"\nFound!!\n";
    else
        cout<<"\nNot Found!!\n";*/
    return 0;
}
