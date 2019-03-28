#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>          
int main()
{
	int fd = chmod("/home/krishna/Desktop/OperatingSystemLab/Day 6/newfile.c",0000);
	printf("%d",fd);
	return 0;
}
