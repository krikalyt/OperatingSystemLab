#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    pid_t abc = fork();
    cout << "Krishna" << endl;
    if(abc==-1)
    {
        std::cout << "Unable to get the instance of a child process" << std::endl;
    }   
    else if(abc==0)
    {
        std::cout << getpid() << "this is child process id" << std::endl;
        std:: cout << getppid() << "this is parent process id of child" << std::endl;
        exit(0);
    } 
    else{
        std::cout << getpid() << "this is parent process id" << std::endl;
        wait(0);
    }
    return 0;
}