#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer k) =
        1 <= k <= n <= 50;
*/

/*@
    logic integer func_result(integer n, integer k) =
        n - k + 1;
*/

/*@
    lemma result_bounds:
        \forall integer n, k;
        valid_range(n, k) ==> 1 <= func_result(n, k) <= 50;
*/

/*@
    requires valid_range(n, k);
    ensures \result == func_result(n, k);
    assigns \nothing;
*/
int func(int n, int k)
{
    // Variable declarations at top of scope
    int result;

    // Precondition verification
    //@ assert 1 <= n && n <= 50;
    //@ assert 1 <= k && k <= 50;
    //@ assert n >= k;
    //@ assert n - k + 1 <= 50;
    //@ assert n - k + 1 >= 1 && n - k + 1 <= 50;

    result = n - k + 1;

    // Postcondition verification
    //@ assert result == func_result(n, k);

    return result;
}
