#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
int main(void)
{
    pid_t pid = fork();
    int status;
    if(pid==0)
    {
        exit(0);
    }
    else{
        pid_t childpid = waitpid(pid,&status,0);
        cout << WIFEXITED(status) << endl;
        cout << childpid << endl;
    }
    return 0;
}