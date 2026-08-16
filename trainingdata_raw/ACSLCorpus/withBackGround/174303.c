#include <stddef.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 10000;

    logic integer compute_res(integer n) = (n + 999) / 1000 * 1000;

    lemma compute_res_lemma:
        \forall integer n; valid_n(n) ==> compute_res(n) == (n + 999) / 1000 * 1000;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_res(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    //@ assert valid_n(n);
    ans = (n + 999) / 1000 * 1000;
    //@ assert ans == compute_res(n);
    return ans;
}
