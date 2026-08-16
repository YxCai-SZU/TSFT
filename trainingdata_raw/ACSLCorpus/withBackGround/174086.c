#include <stddef.h>

/*@
    predicate is_valid_input(integer x, integer n) =
        1 <= x <= 100 && 1 <= n <= 100;

    logic integer compute_result(integer x, integer n) =
        x * (2 * n + 1);
*/

/*@
    requires is_valid_input(x, n);
    ensures \result == compute_result(x, n);
    assigns \nothing;
*/
size_t func(size_t x, size_t n)
{
    // Variable declarations at scope top
    size_t n_prime;
    size_t result;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= n <= 100;

    n_prime = 2 * n + 1;
    //@ assert 1 <= n_prime <= 201;

    //@ assert x * n_prime <= 100 * 201;
    result = x * n_prime;

    //@ assert result == compute_result(x, n);
    return result;
}
