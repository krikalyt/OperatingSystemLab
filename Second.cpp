#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
int main()
{
    pid_t abc = fork();
    if(abc==-1)
    {

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