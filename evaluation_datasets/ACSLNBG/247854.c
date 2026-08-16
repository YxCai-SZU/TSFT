#include <stdbool.h>


bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b;

    if (c >= a && c <= b)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
