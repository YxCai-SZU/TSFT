#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    requires a == (int64_t)a;
    ensures \result == ((a) * 800 - 200);
    assigns \nothing;
*/
int64_t func(uint64_t a)
{
    // Variable declarations at top of scope
    uint64_t x;
    int64_t result;

    //@ assert 1 <= a && a <= 10;
    
    x = a * 800 - 200;
    
    //@ assert x == ((a) * 800 - 200);
    
    result = (int64_t)x;
    return result;
}
