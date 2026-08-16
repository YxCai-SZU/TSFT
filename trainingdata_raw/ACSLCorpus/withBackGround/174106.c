#include <stdint.h>

/*@
    predicate valid_input(integer a, integer p) =
        0 <= a && a <= 100 &&
        0 <= p && p <= 100;

    logic integer total_sum(integer a, integer p) = a * 3 + p;

    predicate loop_invariant(integer temp_sum, integer count, integer sum) =
        0 <= temp_sum && temp_sum <= sum &&
        0 <= count && count <= sum / 2 &&
        temp_sum == sum - 2 * count;
*/

/*@
    requires valid_input(a, p);
    ensures \result >= 0;
    ensures \result <= total_sum(a, p);
    ensures \result == total_sum(a, p) / 2;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t sum;
    int64_t result;
    int64_t temp_sum;
    int64_t count;

    sum = a * 3 + p;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant loop_invariant(temp_sum, count, sum);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    result = count;
    return result;
}
