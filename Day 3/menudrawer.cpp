#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int num,char** args)
{

    pid_t pid = fork();
    if(pid==0)
    {
        while(true)
        {
            cout << "Hi i am krishna" << endl;
        };
        exit(2);
    }else{
        kill(pid,0);
    }
    
    return 0;
}            