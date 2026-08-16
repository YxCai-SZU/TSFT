#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(unsigned long d, unsigned long t, unsigned long s)
{
    // Variable declarations at scope top
    unsigned long product;
    bool result;
    
    //@ assert (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    //@ assert t * s <= 10000 * 10000;
    
    product = t * s;
    result = d <= product;
    
    return result;
}
