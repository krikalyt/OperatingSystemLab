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
  if(pid==0)
  {
    while(true){
      cout << "Hi I am krishna" << endl;
    };
    exit(0);
  }
  else{
    this_thread::sleep_for(chrono::milliseconds(3000));
    int abc = kill(pid,SIGQUIT);
    cout << abc << endl;
    
  }
  return 0;
}
