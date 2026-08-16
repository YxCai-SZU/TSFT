#include <stddef.h>

/*@
    predicate valid_input(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * (m - 1);
*/

/*@
    requires valid_input(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
size_t func(size_t n, size_t m) {
    // Variable declarations at top of scope
    size_t result;

    //@ assert n >= 2 && n <= 100;
    //@ assert m >= 2 && m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    //@ assert (n - 1) * (m - 1) == (n - 1) * (m - 1);

    result = (n - 1) * (m - 1);
    return result;
}
