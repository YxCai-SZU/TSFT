#include <limits.h>


int func(int a, int b)
{
    int result;
    int i = 0;
    
    
    while (i < 1000)
    {
        //@ assert 0 <= i && i <= 1000;
        i = i + 1;
    }
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 1 <= ((a) * (b)) && ((a) * (b)) <= 10000;
    
    result = a * b;
    return result;
}

int main()
{
    return 0;
}
