#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n && n <= 100;

    logic integer square(integer n) = n * n;
    logic integer triple_square(integer n) = 3 * square(n);

    lemma square_bound: \forall integer n; valid_range(n) ==> square(n) <= 100 * 100;
    lemma triple_square_bound: \forall integer n; valid_range(n) ==> triple_square(n) <= 3 * 100 * 100;
    lemma triple_square_identity: \forall integer n, integer sq, integer ans;
        valid_range(n) && sq == square(n) && ans == 3 * sq ==> ans == triple_square(n);
*/

/*@
    requires valid_range(n);
    ensures \result == triple_square(n);
    assigns \nothing;
*/
int32_t func(int32_t n)
{
    int32_t n_squared;
    int32_t ans;

    //@ assert valid_range(n);
    //@ assert square(n) <= 100 * 100;
    n_squared = n * n;

    //@ assert triple_square(n) <= 3 * 100 * 100;
    ans = 3 * n_squared;

    //@ assert ans == triple_square(n);
    return ans;
}
