#include <stdbool.h>


bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    if (b - a == c - b)
    {
        //@ assert ((b) - (a) == (c) - (b));
        result = true;
    }
    else
    {
        //@ assert !((b) - (a) == (c) - (b));
        result = false;
    }
    
    return result;
}
