#include <stdbool.h>

/*@
    requires ((x) > 0 && (x) <= 1000);
    requires ((y) > 0 && (y) <= 1000);
    ensures \result == ((x & y) > 0);
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert ((x) > 0);
    //@ assert ((y) > 0);
    //@ assert x <= 1000;
    //@ assert y <= 1000;
    
    result = (x & y) > 0;
    return result;
}
