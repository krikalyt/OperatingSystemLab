#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>
using namespace std;
#define serverfifo "/home/krishna/Desktop/OperatingSystemLab/Day 6/oneserverdata"
#define abspath "/home/krishna/Desktop/OperatingSystemLab/Day 6/"
#define clientfifo "/home/krishna/Desktop/OperatingSystemLab/Day 6/oneclientdata"
int main(void)
{
    int fd,fdclient;
    int i = 0;
    char* abc = new char[1];
    abc[0] = 0;
    char* filename = new char[100];
    char* returnfifo = new char[100];
    char* returnfifo1 = new char[100];
    char* respondbuffer = new char[100];
    for(size_t i = 0; i < 100; i++)
    {
        filename[i] = 0;
        returnfifo[i] = 0;
        respondbuffer[i] = 0;
	    returnfifo1[i] = 0;
    }
    
    
    mkfifo(serverfifo,0666);
    fd = open(serverfifo,O_RDONLY);
    
    
    

while(true)
{
    i =0;
    while(true)
    {
        read(fd,abc,1);
        
        if(abc[0]==0)
            continue;
        
        if(abc[0]=='\n')
        {
            break;
        }

        filename[i] = abc[0];
        i++;
    }

    i = 0;
    while(true)
    {
        read(fd,abc,1);
        if(abc[0]=='\n')
        {
            break;
        }

        returnfifo[i] = abc[0];
        i++;
    }

    FILE* fp = fopen(filename,"r");
    if(fp==NULL)
    {
        write(2,"Unable to open file...",22);
        continue;
    }
    char c;
    i = 0;
    while((c = fgetc(fp))  != EOF)
    {
        respondbuffer[i] = c;
        i++;
    }
    strcpy(returnfifo1,abspath);
    strcat(returnfifo1,returnfifo);

    
    fdclient = open(returnfifo1,O_WRONLY);
    write(fdclient,respondbuffer,strlen(respondbuffer));
    
    lseek(fd,0,SEEK_SET);
    fclose(fp);
    close(fdclient);   

    for(size_t i = 0; i < 100; i++)
    {
        filename[i] = 0;
        returnfifo[i] = 0;
        respondbuffer[i] = 0;
	    returnfifo1[i] = 0;
    }
     
//ending of main while loop
}
    close(fd);
    return 0;
}
