#include <stdint.h>

/*@
    predicate valid_n(integer n) = 2 <= n && n <= 100;

    logic integer half(integer n) = n / 2;
    logic integer half_plus_one(integer n) = (n + 1) / 2;

    lemma half_bounds:
        \forall integer n; valid_n(n) ==> 1 <= half(n) && half(n) <= 50;

    lemma half_plus_one_bounds:
        \forall integer n; valid_n(n) ==> 1 <= half_plus_one(n) && half_plus_one(n) <= 51;

    lemma multiplication_bounds:
        \forall integer n; valid_n(n) ==> half(n) * half_plus_one(n) <= 50 * 51;
*/

/*@
    requires valid_n(n);
    ensures \result == half(n) * half_plus_one(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t half_n_plus_one;
    uint64_t ans;

    //@ assert valid_n(n);
    half_n = n / 2;
    half_n_plus_one = (n + 1) / 2;

    //@ assert half_n == half(n);
    //@ assert half_n_plus_one == half_plus_one(n);

    //@ assert 1 <= half_n && half_n <= 50;
    //@ assert 1 <= half_n_plus_one && half_n_plus_one <= 51;

    //@ assert half_n * half_n_plus_one <= 50 * 51;
    ans = half_n * half_n_plus_one;

    //@ assert ans == half(n) * half_plus_one(n);
    return ans;
}
