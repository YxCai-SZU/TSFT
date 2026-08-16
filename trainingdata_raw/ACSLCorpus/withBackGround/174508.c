#include <stddef.h>

/*@
    predicate valid_params(integer n, integer m) =
        2 <= m && m <= n && n <= 100000;

    logic integer lower_bound(integer n, integer m) =
        (n - 2) / (m - 1) + 1;

    logic integer upper_bound(integer n, integer m) =
        (n - 2) / (m - 1) + 2;

    lemma bounds_relation:
        \forall integer n, m;
        valid_params(n, m) ==> lower_bound(n, m) <= upper_bound(n, m);
*/

/*@
    requires valid_params(n, m);
    assigns \nothing;
    ensures \result <= upper_bound(n, m);
    ensures \result >= lower_bound(n, m);
*/
size_t func(size_t n, size_t m)
{
    size_t ans;

    //@ assert valid_params(n, m);
    ans = (n - 2) / (m - 1) + 1;

    //@ assert ans <= upper_bound(n, m);
    //@ assert ans >= lower_bound(n, m);

    return ans;
}
