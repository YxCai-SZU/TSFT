#include <stddef.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c, integer d) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= d && d <= 100;

    logic integer total_sum(integer a, integer b, integer c, integer d) = a + b + c + d;

    lemma result_bound: \forall integer a, b, c, d, r;
        is_valid_params(a, b, c, d) && r == (total_sum(a, b, c, d) / 2) + 1 ==> r >= 0;
*/

/*@
    requires is_valid_params(a, b, c, d);
    ensures \result <= (a + b + c + d) / 2 + 1;
    ensures \result >= 0;
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t sum;
    size_t result;
    size_t count;
    size_t half_sum;
    size_t temp_sum;

    sum = a + b + c + d;
    result = 0;
    count = 0;
    half_sum = 0;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum;
        loop invariant 0 <= half_sum;
        loop invariant sum == a + b + c + d;
        loop invariant temp_sum + 2 * half_sum == sum;
        loop assigns temp_sum, half_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        half_sum += 1;
        temp_sum -= 2;
    }

    /*@
        loop invariant 0 <= sum;
        loop invariant 0 <= result;
        loop invariant sum + 2 * result == a + b + c + d;
        loop assigns sum, result;
        loop variant sum;
    */
    while (sum >= 2)
    {
        sum -= 2;
        result += 1;
    }

    if (sum == 1)
    {
        result += 1;
    }

    //@ assert result <= (a + b + c + d) / 2 + 1;
    //@ assert result >= 0;
    return result;
}
