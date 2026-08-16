#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer square(integer n) = n * n;
    logic integer triple_square(integer n) = square(n) * 3;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triple_square(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t res;
    
    //@ assert n > 0 && n <= 100;
    //@ assert n * n <= 10000;
    //@ assert n * n * 3 <= 30000;
    
    res = n * n * 3;
    return res;
}
