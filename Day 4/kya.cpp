#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <thread>
using namespace std;
int main()
{
  int abc = system("ps -A");
  cout << abc << endl;
  return 0;
}
