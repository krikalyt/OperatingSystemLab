#include <iostream>
using namespace std;
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
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
    char* abc = new char[90];
    read(FDs[0],abc,strlen(arg));
    execl("/usr/bin/xterm","/usr/bin/xterm","-e","man",abc,NULL);
    exit(0);
  }
  else{
    close(FDs[0]);
    write(FDs[1],arg,strlen(arg));
    wait(0);
  }
  return 0;
}
