#include <stdbool.h>

/*@
    requires (0 < (x) && (x) <= 10) && (0 < (y) && (y) <= 10);
    ensures ((\result) == ((x) * (x) <= (y) * 10));
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 < x && x <= 10;
    //@ assert 0 < y && y <= 10;
    
    //@ assert x * x <= 100;
    //@ assert y * 10 <= 100;
    
    result = (x * x <= y * 10);
    
    //@ assert ((result) == ((x) * (x) <= (y) * 10));
    return result;
}
