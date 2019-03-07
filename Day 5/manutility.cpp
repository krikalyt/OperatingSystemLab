#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
  pid_t pid;
  char line[80];
  int n;
  int FDs[2];
  pipe(FDs);
  pid = fork();
  if(pid==0)
  {
    close(FDs[1]);
    dup2(FDs[0],0);
    execl("/usr/bin/sort","/usr/bin/sort",0);
    exit(0);
  }
  else{
    close[FDs[0]];
    dup2(FDs[1],1);
    execl("/bin/ls","bin/ls","-l",0);
    wait(0);
  }
  return 0;
}
