#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t abc = fork();
    cout << "This will run twice" << endl;
    if(abc==-1)
    {
        std::cout << "Unable to get the instance of a child process" << std::endl;
    }   
    else if(abc==0)
    {
        cout << "Child process will be kept in sleep for five second and main process will wait for child process" << endl;
        sleep(5);
    } 
    else{
        
        cout << "Main process waiting started" << endl;
        wait(0);
        std::cout << "Main Process wait has been completed..."  << std::endl;
    }
    return 0;
}