#include <iostream>
using namespace std;
#include <sys/wait.h>
#include <unistd.h>
int main(int num,char** args)
{
  char* arg = args[1];
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
    char* abc = new char[10];
    cin >> abc;
    execl("/usr/bin/xterm","/usr/bin/xterm","-e","man",abc,NULL);
    exit(0);
  }
  else{
    close(FDs[0]);
    dup2(FDs[1],1);
    execl("/bin/echo","/bin/echo",arg,NULL);
    wait(0);
  }
  return 0;
}