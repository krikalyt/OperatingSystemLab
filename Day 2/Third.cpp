#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main()
{
    pid_t abc = fork();
    if(abc == -1)
    {
        cout << "unable to create child process" << endl;
    }
    else if(abc==0)
    {
        cout <<"in child process first parent id " <<  getppid() << endl;
        cout <<"in child process first child id " <<  getpid() << endl;

        pid_t pid = fork();
        if(pid==-1){
            cout << "unable to create child process of child process " << endl;
        }else if(pid==0){
            cout <<"in child process first of child process " <<  getpid() << endl;
            cout <<"in child process first of child process " <<  getppid() << endl;
        }else{
            wait(0);
            cout << "Running in " << endl;
        };
    }
    else{
        wait(0);
    }
    return 0;
}