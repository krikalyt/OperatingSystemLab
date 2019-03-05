//code for tree process
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <thread>
using namespace std;
int main()
{
  pid_t pid = fork();
  pid_t pid2 = fork();
  for (size_t i = 0; i < 1; i++) {
    cout << getpid() << endl;
    if(pid==0){
      pid = fork();
    }
    if(pid2==0){
      pid = fork();
      pid2 = fork();
    }

    if(pid!=0){
      break;
    }

    if(pid2!=0){
      break;
    }
  }
  return 0;
}
