#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(void)
{
  char line[80];
  int FDs[2];
  pipe(FDs);
  pid_t pid = fork();
  if(pid==0)
  {
    close(FDs[1]);
    int n = read(FDs[0],line,80);
    write(1,line,n);
    exit(1);
  }
  else{
    close(FDs[0]);
    write(FDs[1],"Hello Krishna\n",13);
    wait(NULL);
  }
  return 0;
}
