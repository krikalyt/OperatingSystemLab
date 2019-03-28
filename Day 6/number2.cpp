#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h> 
#include <fcntl.h> 
int main(void)
{
    int fd;
    char* filename = "/home/krishna/Desktop/OperatingSystemLab/Day 6/number2data";
    mkfifo(filename,0666);
    char arr[250];
    pid_t pid = fork();
    if(pid==0){
        
        fd = open(filename, O_RDONLY);
        dup2(fd,0);
        execl("/usr/bin/sort","/usr/bin/sort",NULL);
        close(fd);
        exit(0);
    }else{
        fd = open(filename, O_WRONLY); 
        dup2(fd,1);
        execl("/bin/ps","/bin/ps","-A",NULL);
        close(fd); 
        wait(0);
    }
    return 0;
}