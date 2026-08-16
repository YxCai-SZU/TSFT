#include <stdint.h>

/*@
    predicate is_square_pre(uint32_t n) = n < 0x10000;
    predicate is_square_post(uint32_t n, uint32_t ret) = ret == n * n;
*/

/*@
    requires is_square_pre(n);
    ensures is_square_post(n, \result);
    assigns \nothing;
*/
uint32_t is_square(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n < 0x10000;
    //@ assert n * n < 0x100000000;
    
    result = n * n;
    
    //@ assert result == n * n;
    return result;
}

/*@
    lemma square_bound: \forall uint32_t n; n < 0x10000 ==> n * n < 0x100000000;
*/
