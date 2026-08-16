#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (((k) * 500) >= x);
    assigns \nothing;
*/
bool func(unsigned long k, unsigned long x)
{
    // Variable declarations at scope top
    unsigned long en;
    bool result;

    //@ assert (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    
    en = 500 * k;
    
    //@ assert en == ((k) * 500);
    //@ assert 500 <= en <= 50000;
    
    result = (en >= x);
    
    return result;
}
