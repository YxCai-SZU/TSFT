#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000);
    requires (1 <= (t) <= 10000);
    requires (1 <= (s) <= 10000);
    ensures \result == (s * t >= d);
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product;

    //@ assert s <= 10000;
    //@ assert t <= 10000;
    //@ assert s * t <= 10000 * 10000;

    product = s * t;
    result = (product >= d);
    
    return result;
}
