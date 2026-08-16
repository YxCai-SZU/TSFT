#include <stddef.h>

/*@
    predicate valid_params(integer n, integer d) =
        1 <= n && n <= 20 &&
        1 <= d && d <= 20;

    logic integer compute_man(integer n, integer d) =
        (n + 2 * d - 1) / (2 * d);

    lemma man_bounds:
        \forall integer n, d;
        valid_params(n, d) ==>
        compute_man(n, d) >= 1 &&
        compute_man(n, d) <= n;
*/

/*@
    requires valid_params(n, d);
    ensures \result >= 1;
    ensures \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t d)
{
    size_t man;

    //@ assert valid_params(n, d);
    man = (n + 2 * d - 1) / (2 * d);
    //@ assert man == compute_man(n, d);
    //@ assert man >= 1 && man <= n;

    return man;
}
