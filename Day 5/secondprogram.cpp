#include <iostream>
using namespace std;
#include <sys/wait.h>
#include <unistd.h>
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
    execl("/usr/bin/sort","/usr/bin/sort",NULL);
    exit(0);
  }
  else{
    close(FDs[0]);
    dup2(FDs[1],1);
    execl("/bin/ls","/bin/ls",NULL);
    wait(0);
  }
  return 0;
}