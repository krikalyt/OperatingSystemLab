#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int num,char** args)
{
    char* abc = args[1];
    char* abc2 = "xterm -e man ";
    char* command = new char[strlen(abc) + strlen(abc2) + 1];
    strcpy(command,abc2);
    strcat(command,abc);
    system(command);
    return 0;
}