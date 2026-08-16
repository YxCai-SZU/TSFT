#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires a == (int64_t)a && b == (int64_t)b;
    ensures \result == ((a) * (b));
    ensures \result == (int64_t)\result;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    result = a * b;
    return result;
}
