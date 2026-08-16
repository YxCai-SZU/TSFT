#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures ((\result) == (a) * (a));
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert ((a) * (a) <= 10000);
    
    result = a * a;
    
    //@ assert ((result) == (a) * (a));
    return result;
}
