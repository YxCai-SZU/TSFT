/*@
    predicate sum_invariant(integer temp_sum, integer sum, integer count) =
        temp_sum <= sum &&
        temp_sum >= 0 &&
        temp_sum + 2 * count == sum;

    lemma division_lemma:
        \forall integer sum, integer count, integer temp_sum;
        sum_invariant(temp_sum, sum, count) && temp_sum < 2 ==>
        count == sum / 2;
*/

#include <stdint.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result <= p + a * 3;
    ensures \result == (p + a * 3) / 2;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t sum;
    uint32_t result;
    uint32_t temp_sum;
    uint32_t count;

    sum = p + a * 3;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant sum_invariant(temp_sum, sum, count);
        loop invariant sum == p + a * 3;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert sum_invariant(temp_sum, sum, count);
    }

    //@ assert temp_sum < 2;
    //@ assert sum_invariant(temp_sum, sum, count);
    //@ assert count == sum / 2;

    result = count;
    return result;
}
