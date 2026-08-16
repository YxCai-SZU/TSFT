#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;
    
    logic integer compute_result(integer n, integer m) =
        n * m - m + 1;
    
    lemma bounds_lemma:
        \forall integer n, m;
            valid_range(n, m) ==> 1 <= n * m <= 10000;
    
    lemma result_bounds_lemma:
        \forall integer n, m;
            valid_range(n, m) && n * m <= 10000 ==> 
            compute_result(n, m) <= 10000;
*/

/*@
    requires valid_range(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert valid_range(n, m);
    
    //@ assert 1 <= n * m <= 10000;
    
    result = n * m - m + 1;
    
    //@ assert result == compute_result(n, m);
    
    //@ assert result <= 10000;
    
    return result;
}
