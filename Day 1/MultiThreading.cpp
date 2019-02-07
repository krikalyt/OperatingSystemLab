#include <iostream>
using namespace std;
#include <chrono>
int main()
{
    auto now = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000000; i++)
    {
        
    }
    auto last = chrono::high_resolution_clock::now();
    chrono::duration<double> abc;
    abc= last-now;
    cout << abc.count() << endl;
    return 0;
}