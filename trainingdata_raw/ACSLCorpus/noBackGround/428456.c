#include <stdint.h>

/*@
    requires (1 <= (s) && (s) <= 100);
    ensures \result == ((s) * (s));
    assigns \nothing;
*/
int64_t func(int64_t s)
{
    // Variable declarations at top of scope
    int64_t res;

    //@ assert (1 <= (s) && (s) <= 100);
    //@ assert ((s) * (s)) <= 10000;
    
    res = s * s;
    
    //@ assert res == ((s) * (s));
    return res;
}
