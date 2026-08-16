#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    lemma square_bounds: \forall integer n; is_valid_n(n) ==> 1 <= square(n) && square(n) <= 10000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == square(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert is_valid_n(n);
    //@ assert 1 <= square(n) && square(n) <= 10000;
    
    result = n * n;
    //@ assert result == square(n);
    return result;
}
