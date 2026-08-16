#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;

    logic integer square(integer n) = n * n;

    lemma square_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
    lemma no_underflow: \forall integer n, a; valid_params(n, a) ==> n * n >= a;
    lemma result_value: \forall integer n, a; valid_params(n, a) ==> square(n) - a == square(n) - a;
*/

/*@
    requires valid_params(n, a);
    ensures \result == square(n) - a;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    //@ assert n * n >= a;
    //@ assert n * n <= 18446744073709551615;
    //@ assert n * n - a <= 18446744073709551615;

    result = n * n - a;
    return result;
}
