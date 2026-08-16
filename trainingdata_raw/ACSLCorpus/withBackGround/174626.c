#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 10000;

    logic integer compute_res(integer n) = (n + 999) / 1000;

    lemma res_bound: \forall integer n; valid_n(n) ==> compute_res(n) <= 1000;
*/

/*@
    requires valid_n(n);
    assigns \nothing;
    ensures \result <= 1000;
    ensures \result == compute_res(n);
*/
size_t func(size_t n)
{
    size_t res;
    //@ assert valid_n(n);
    res = (n + 999) / 1000;
    //@ assert res == compute_res(n);
    //@ assert res <= 1000;
    return res;
}
