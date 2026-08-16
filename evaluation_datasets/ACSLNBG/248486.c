#include <stdbool.h>


bool func(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert (0 <= (x) <= 255);
    //@ assert (0 <= (y) <= 255);
    //@ assert (0 <= (z) <= 255);
    
    //@ assert (x & y & z) == (z & y & x);
    
    return ((x & y & z) == 0) || ((x & y & z) == 255);
}
