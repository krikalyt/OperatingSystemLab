#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    
    pid_t pid = fork();
    switch (pid)
    {
        case -1:{
            cout << "system was unable to generate child process." << endl;
            break;
        }

        case 0:{

            cout << "this is running in child process." << endl;
            exit(0);
            break;
        }  
    
        default:{

            cout << "this is running in main process." << endl;
            break;
        }   
    }

    wait(0);
    return 0;
}