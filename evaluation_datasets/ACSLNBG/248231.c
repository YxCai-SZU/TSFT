#include <stdbool.h>


bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a + b <= 0xffffffff;
    //@ assert a + c <= 0xffffffff;
    //@ assert b + c <= 0xffffffff;

    if (a + b == c || a + c == b || b + c == a)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
