#include <iostream>
using namespace std;
#include <stdlib.h>
int main(int num,char** abc,char** env)
{
    setenv("myname","Krishna",1);
    return 0;
}