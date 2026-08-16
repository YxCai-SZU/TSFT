#include <stddef.h>

/*@
    predicate valid_input(integer m) = 1 <= m <= 10000;
    predicate loop_invariant(integer m, integer temp_m, integer div) =
        0 <= temp_m <= m &&
        div <= m / 1000 &&
        temp_m == m - div * 1000;
    logic integer compute_result(integer m, integer temp_m) =
        (1000 - temp_m) % 1000;
*/

/*@
    requires valid_input(m);
    ensures \result >= 0 && \result < 1000;
    ensures \result == compute_result(m, m % 1000);
*/
size_t func(size_t m)
{
    size_t ans;
    size_t temp_m;
    size_t div;
    
    ans = 0;
    temp_m = m;
    div = 0;
    
    /*@
        loop invariant loop_invariant(m, temp_m, div);
        loop assigns temp_m, div;
        loop variant temp_m;
    */
    while (temp_m >= 1000)
    {
        //@ assert temp_m >= 1000;
        temp_m -= 1000;
        div += 1;
    }
    
    //@ assert temp_m == m % 1000;
    ans = (1000 - temp_m) % 1000;
    
    //@ assert ans == compute_result(m, temp_m);
    return ans;
}
