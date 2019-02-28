#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;
int main()
{
    pid_t pid = fork();
    if(pid==0)
    {
        execl("/bin/ls","bin/ls","-l",0);
    }
    else if(pid==-1)
    {
        cout << "Unable to make child process.." << endl;
    }
    else{
        pid_t process = getpid();
        abort();
    }
    return 0;
}