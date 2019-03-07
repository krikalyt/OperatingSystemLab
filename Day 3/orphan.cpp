#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <thread>
using namespace std;
int main()
{
    int status;
    pid_t pid = fork();
    if(pid==0)
    {
        cout << "child pid is " << getpid() << endl;
        this_thread::sleep_for(chrono::milliseconds(10000));
        cout << "Krishna is Here " << endl;
        exit(0);
    }
    else if(pid==-1)
    {
        cout << "Unable to make child process.." << endl;
    }
    else
    {
        
    }
    return 0;
}