#include <stdbool.h>

/*@
    requires x >= 1 && x <= 0xffffffff;
    requires y >= 1 && y <= 0xffffffff;
    ensures \result == ((x & y) == (y & x));
    ensures \result == true;
*/
bool func(unsigned int x, unsigned int y)
{
    bool result;

    //@ assert (((x) & (y)) == ((y) & (x)));
    
    result = ((x & y) == (y & x));
    
    //@ assert result == true;
    
    return result;
}
