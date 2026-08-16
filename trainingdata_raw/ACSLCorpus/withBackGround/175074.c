#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/*@
    predicate is_valid_mul(integer n, integer m, integer result) =
        (n > 0 && m > 0) ==>
            ((n <= 10000 && m <= 10000) ==> result == n * m);
*/

/*@
    logic integer safe_mul(integer n, integer m) =
        (n == 0 || m == 0) ? 0 : n * m;
*/

/*@
    lemma mul_bounds:
        \forall integer n, m;
            0 <= n <= 10000 && 0 <= m <= 10000 ==>
                safe_mul(n, m) <= UINT32_MAX;
*/

/*@
    requires 0 <= n <= 10000;
    requires 0 <= m <= 10000;
    ensures \result == 0 || \result == n * m;
    ensures \result <= UINT32_MAX;
*/
uint32_t func(uint32_t n, uint32_t m) {
    uint32_t result;
    
    //@ assert n <= 10000 && m <= 10000;
    
    if (n > 0 && m > 0) {
        if (n > 10000 || m > 10000) {
            result = 0;
        } else {
            //@ assert n <= 10000 && m <= 10000;
            //@ assert n * m <= UINT32_MAX;
            result = n * m;
        }
    } else {
        //@ assert n == 0 || m == 0;
        result = 0;
    }
    
    //@ assert result == 0 || result == n * m;
    return result;
}
