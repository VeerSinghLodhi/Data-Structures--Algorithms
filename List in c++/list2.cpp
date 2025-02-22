#include<iostream>
#include<list>
using namespace std;
struct Task{
    string name;
    int priority;
};
class TaskScheduler{
public:
    list<struct Task>tasks;
    void addTask(string name,int priority)
    {
        tasks.push_back({name,priority});
    }
    void removeTask(string name)
    {
        for(auto i=tasks.begin();i!=tasks.end();i++)
        {
            if(i->name==name){
                tasks.erase(i);
                break;
            }

        }
    }
    void updateTaskPriority(string name,int newPriority)
    {
        /*for(auto i=tasks.begin();i!=tasks.end();i++)
        {

        }*/
        for(auto &task : tasks){
            if(task.name==name){
                task.priority=newPriority;
                break;
            }

        }
    }
    void displayTasks()
    {
        if(tasks.empty()){
            cout<<"\nNot Tasks available\n\n";
        }
        else{
            for(auto task :tasks)
            {
                cout<<task.name<<", Priority: "<<task.priority<<endl;
            }
        }
    }
    static bool comparePriority(const Task &a,const Task &b){
        return a.priority<b.priority;
    }
    void sortPriority(){
    tasks.sort(comparePriority);
    }
    void taskClear()
    {
        tasks.clear();
    }
};
int main()
{
    TaskScheduler t1;
    t1.addTask("Complete Assignment",3);
    t1.addTask("Prepare Presentation",1);
    t1.addTask("Prepare Project",2);
    t1.addTask("Submit Assignment",0);

    cout<<"\nTasks before sorting..."<<endl<<endl;
    t1.displayTasks();

    t1.sortPriority();
    cout<<"\nTasks After sorting..."<<endl<<endl;
    t1.displayTasks();

    t1.updateTaskPriority("Complete Assignment",10);
    t1.updateTaskPriority("Prepare Project",5);
    t1.updateTaskPriority("Submit Assignment",12);

    cout<<"\nTasks After Updating..."<<endl<<endl;
    t1.displayTasks();

    t1.sortPriority();
    cout<<"\nTasks Again After sorting..."<<endl<<endl;
    t1.displayTasks();

    t1.removeTask("Prepare Presentation");
    cout<<"\nTasks After delete one element..."<<endl<<endl;
    t1.displayTasks();

    cout<<"\nTack After Clearing...."<<endl<<endl;
    t1.taskClear();
    t1.displayTasks();
}
