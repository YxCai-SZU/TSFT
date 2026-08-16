#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n <= 2959;

    logic integer triangular_number(integer n) = n * (n + 1) / 2;

    lemma triangular_bounds: \forall integer n; is_valid_n(n) ==> 
        0 <= triangular_number(n) <= 4294967295;
*/

/*@
    requires is_valid_n(n);
    ensures \result == triangular_number(n);
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n <= 2959;
    //@ assert n * (n + 1) / 2 <= 2959 * (2959 + 1) / 2;
    //@ assert n * (n + 1) >= 0;
    //@ assert n * (n + 1) <= 4294967295;

    result = n * (n + 1) / 2;
    //@ assert result == triangular_number(n);
    
    return result;
}
