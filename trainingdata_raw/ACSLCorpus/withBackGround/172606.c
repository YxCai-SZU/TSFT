#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;
    
    logic integer compute_result(integer n, integer m) =
        n < 10 && m < 10 ? n * m : -1;
    
    lemma multiplication_bounds:
        \forall integer n, m;
            n >= 1 && n <= 9 && m >= 1 && m <= 9 ==> n * m <= 81;
*/

/*@
    requires valid_input(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at top of scope
    int64_t result;
    
    if (n < 10 && m < 10)
    {
        //@ assert n >= 1 && n <= 9;
        //@ assert m >= 1 && m <= 9;
        //@ assert n * m <= 81;
        result = n * m;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
