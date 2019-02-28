#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
int main()
{
    char* const abc[] = {"/bin/ls",0};
    pid_t pid = fork();
    if(pid==0)
    {
        execv(abc[0],abc);
        exit(0);
    }
    else if(pid==-1)
    {
        cout << "Unable to make child process.." << endl;
    }
    else{
        wait(0);
    }
    return 0;
}