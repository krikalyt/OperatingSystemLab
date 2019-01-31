#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    cout << getpid() << endl;
    for(int i = 0; i < 10000000000; i++)
    {
        cout << getpid() << endl;
    }
    
    return 0;
}