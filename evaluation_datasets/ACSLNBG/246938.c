#include <stdbool.h>


bool func(int x, int y)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((x) + (y) <= 16);
    
    result = (x <= 8 && y <= 8);
    return result;
}
