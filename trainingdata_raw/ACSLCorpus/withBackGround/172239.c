#include <stddef.h>

/*@
    predicate valid_range(integer n, integer d) =
        1 <= n <= 20 && 1 <= d <= 20;

    logic integer calculate_ans(integer n, integer d) =
        (n + 2 * d - 1) / (2 * d);

    lemma ans_bounds:
        \forall integer n, d;
        valid_range(n, d) ==> 0 <= calculate_ans(n, d) <= n;
*/

/*@
    requires valid_range(n, d);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t d)
{
    size_t ans;

    //@ assert valid_range(n, d);
    ans = (n + 2 * d - 1) / (2 * d);
    
    //@ assert ans == calculate_ans(n, d);
    //@ assert ans >= 0;
    //@ assert ans <= n;
    
    return ans;
}
