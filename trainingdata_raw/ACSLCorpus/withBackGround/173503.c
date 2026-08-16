#include <stdint.h>

/*@
    predicate is_valid_input(integer n) = 0 <= n <= 1000000;

    logic integer half_plus_remainder(integer n) = n / 2 + n % 2;

    lemma half_plus_remainder_lemma: \forall integer n; is_valid_input(n) ==> half_plus_remainder(n) == n / 2 + n % 2;
*/

/*@
    requires is_valid_input(n);
    ensures \result == half_plus_remainder(n);
    ensures \result == n / 2 + n % 2;
*/
uint32_t func(uint32_t n)
{
    uint32_t half;
    uint32_t remainder;
    uint32_t result;

    half = n / 2;
    remainder = n % 2;
    result = half + remainder;

    //@ assert result == n / 2 + n % 2;

    return result;
}
