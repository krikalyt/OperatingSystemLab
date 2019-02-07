#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    cout << getpid() << endl;
    cout << getppid() << endl;
    return 0;
}
