#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    // Logical computation for maximum
    logic integer max_val(integer a, integer b) = (a > b) ? a : b;

    // Proof lemma for multiplication bounds
    lemma mul_bounds: \forall integer n, m;
        valid_range(n) && valid_range(m) && n <= 9 && m <= 9 ==> 
        n * m <= 81 && n * m >= 1;
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures (n > 9 && m > 9 ==> \result == 9) &&
            (n <= 9 && m <= 9 ==> \result == n * m) &&
            (n > 9 && m <= 9 ==> \result == 9) &&
            (n <= 9 && m > 9 ==> \result == 9);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t max_val;
    uint32_t result;

    // Declare all variables at scope top
    max_val = (n > m) ? n : m;

    if (max_val > 9)
    {
        result = 9;
        //@ assert max_val > 9 ==> result == 9;
    }
    else
    {
        //@ assert n <= 9 && m <= 9;
        //@ assert n * m <= 81;
        //@ assert n * m >= 1;
        result = n * m;
    }

    return result;
}
