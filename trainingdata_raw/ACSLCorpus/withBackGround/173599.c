#include <stdint.h>

/*@ predicate is_small(integer x) = 1 <= x <= 9; */

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n > 9 || m > 9) ==> \result == -1;
    ensures (n <= 9 && m <= 9) ==> \result == n * m;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    
    if (n > 9 || m > 9) {
        result = -1;
    } else {
        //@ assert is_small(n);
        //@ assert is_small(m);
        //@ assert n * m <= 81;
        result = (int32_t)(n * m);
    }
    
    return result;
}
