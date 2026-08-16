#include <stdbool.h>


bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    bool answer = true;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;
    
    if (a >= b)
    {
        answer = false;
    }
    
    if (b >= c)
    {
        answer = false;
    }
    
    if (c >= d)
    {
        answer = false;
    }
    
    //@ assert answer == true <==> ((a) < (b) && (b) < (c) && (c) < (d));
    
    return answer;
}
