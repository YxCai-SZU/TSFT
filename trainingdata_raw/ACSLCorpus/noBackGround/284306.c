#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (x) <= 200);
    ensures \result == (a <= x && x - a <= b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert a + b <= 200;
    //@ assert x - a <= 200;
    
    result = (a <= x) && (x - a <= b);
    return result;
}
