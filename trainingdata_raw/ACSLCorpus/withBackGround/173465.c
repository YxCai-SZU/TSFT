#include <stddef.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer half(integer n) = n / 2;
    logic integer remainder(integer n) = n % 2;
    logic integer expected_result(integer n) = half(n) + remainder(n);

    lemma half_definition: \forall integer n; is_valid_n(n) ==> half(n) == n / 2;
    lemma remainder_definition: \forall integer n; is_valid_n(n) ==> remainder(n) == n % 2;
    lemma sum_bound: \forall integer n; is_valid_n(n) ==> half(n) + remainder(n) <= n;
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t half;
    size_t remainder;
    size_t result;

    half = n / 2;
    remainder = n % 2;

    //@ assert half == n / 2;
    //@ assert remainder == n % 2;
    //@ assert half + remainder <= n;

    result = half + remainder;
    return result;
}
