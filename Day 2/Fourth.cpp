#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(int number,char **args)
{
    string abc = args[1];
    int num = stoi(abc);
    
    for(int i=0;i<num;i++){
        fork();
    }
    cout << "krishna" << endl;
    wait(0);
    return 0;
}