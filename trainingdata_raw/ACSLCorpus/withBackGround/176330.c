#include <stdint.h>

/*@
    predicate is_small_pair(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    predicate both_small(integer n, integer m) =
        n <= 8 && m <= 8;

    predicate either_large(integer n, integer m) =
        n > 8 || m > 8;
*/

/*@
    requires is_small_pair(n, m);
    assigns \nothing;
    ensures both_small(n, m) ==> \result == 1;
    ensures either_large(n, m) ==> \result == 2;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    //@ assert is_small_pair(n, m);
    
    if (n <= 8 && m <= 8) {
        result = 1;
        //@ assert both_small(n, m) ==> result == 1;
    } else {
        result = 2;
        //@ assert either_large(n, m) ==> result == 2;
    }
    
    return result;
}
