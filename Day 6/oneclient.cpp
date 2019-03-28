#include <stdio.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>
#define serverfifo "/home/krishna/Desktop/OperatingSystemLab/Day 6/oneserverdata"
#define abspath "/home/krishna/Desktop/OperatingSystemLab/Day 6/"
#define clientfifo "/home/krishna/Desktop/OperatingSystemLab/Day 6/oneclientdata"
int main(void)
{
  int FDs[2];
  char filenamebuffer[100];
  for(size_t i = 0; i < 100; i++)
  {
    filenamebuffer[i] = 0;
  }
  
  
  char returndata[100];
  std::cout << "Enter the File name : " << std::endl;
  std::cin >> filenamebuffer;
  strcat(filenamebuffer,"\n");
  strcat(filenamebuffer,"oneclientdata\n");
  FDs[0] = open(serverfifo,0666);
  write(FDs[0],filenamebuffer,strlen(filenamebuffer));
  FDs[1] = open(clientfifo,0666);
  read(FDs[1],returndata,100);
  std::cout << returndata << std::endl;
  close(FDs[0]);
  close(FDs[1]);
  return 0;
}
