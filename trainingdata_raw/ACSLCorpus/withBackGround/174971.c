#include <stdint.h>

/*@
    predicate is_square(integer n, integer result) =
        result == n * n;

    lemma square_nonnegative:
        \forall integer n; n >= 0 ==> n * n >= 0;
*/

/*@
    requires n < 46340;
    ensures \result == n * n;
    ensures \result >= 0;
*/
uint32_t find_square_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n * n >= 0;
    
    result = n * n;
    
    //@ assert result == n * n;
    //@ assert result >= 0;
    
    return result;
}
