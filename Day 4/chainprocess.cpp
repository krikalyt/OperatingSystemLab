//code for chain process
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
  for (size_t i = 0; i < 4; i++) {
    cout << getpid() << endl;

    if(pid==0){
      pid = fork();
    }

    if(pid!=0){
      break;
    }
  }
  return 0;
}
