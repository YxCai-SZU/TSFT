#include <stdint.h>

/*@
    predicate is_nonnegative(integer val) = val >= 0;
    predicate is_in_range(integer val) = 1 <= val <= 1000000000000000;
*/

/*@
    logic integer even_part(integer x) = x / 2;
    logic integer odd_part(integer x) = x - even_part(x);
    logic integer result_value(integer x) = (even_part(x) + odd_part(x)) * 2;
*/

/*@
    lemma even_odd_sum: \forall integer x; x == even_part(x) + odd_part(x);
    lemma even_nonnegative: \forall integer x; is_in_range(x) ==> even_part(x) >= 0;
    lemma odd_nonnegative: \forall integer x; is_in_range(x) ==> odd_part(x) >= 0;
    lemma sum_bound: \forall integer x; is_in_range(x) ==> even_part(x) + odd_part(x) <= 2 * x;
    lemma result_even: \forall integer x; is_in_range(x) ==> result_value(x) % 2 == 0;
    lemma result_lower_bound: \forall integer x; is_in_range(x) ==> result_value(x) >= x;
    lemma result_upper_bound: \forall integer x; is_in_range(x) ==> result_value(x) <= 2 * x;
    lemma result_min_bound: \forall integer x; is_in_range(x) ==> result_value(x) >= 2 * (x / 2);
*/

/*@
    requires 1 <= x <= 1000000000000000;
    ensures \result % 2 == 0;
    ensures \result >= x;
    ensures \result <= 2 * x;
    ensures \result >= 2 * (x / 2);
*/
uint64_t func(uint64_t x)
{
    uint64_t even;
    uint64_t odd;
    uint64_t result;

    even = x / 2;
    odd = x - even;

    //@ assert x == even + odd;
    //@ assert even >= 0;
    //@ assert odd >= 0;
    //@ assert even + odd <= 2 * x;

    result = (even + odd) * 2;
    return result;
}
