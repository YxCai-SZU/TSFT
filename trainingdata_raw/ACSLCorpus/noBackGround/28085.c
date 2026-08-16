#include <stdint.h>

/*@
    requires ((a) >= 0);
    requires ((a) >= 0 && (a) <= 100);
    ensures ((\result) == (a) * (a));
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert ((a) >= 0);
    //@ assert ((a) >= 0 && (a) <= 100);
    //@ assert ((a) * (a) <= 10000);
    
    result = a * a;
    
    //@ assert ((result) == (a) * (a));
    
    return result;
}
