#include <stdio.h>
#include <unistd.h>
int main()
{

    printf("%d\n",getpid());
    printf("%d",getppid());

    for(int i = 0; i < 5; i++)
    {
        /* code */
    }
    
    return 0;
}