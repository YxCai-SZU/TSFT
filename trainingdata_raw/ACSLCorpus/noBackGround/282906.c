#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) > (c) ? (a) - (c) : (c) - (a));
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t diff;
    
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    
    if (a > c)
    {
        diff = a - c;
        //@ assert diff == a - c;
    }
    else
    {
        diff = c - a;
        //@ assert diff == c - a;
    }
    
    //@ assert diff == ((a) > (c) ? (a) - (c) : (c) - (a));
    
    return (int32_t)diff;
}
