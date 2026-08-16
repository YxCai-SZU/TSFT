#include <stdint.h>

/*@
    predicate sum_in_range(integer a, integer p, integer s) =
        0 <= a <= 100 && 0 <= p <= 100 && s == a * 3 + p;
*/

/*@
    logic integer compute_sum(integer a, integer p) = a * 3 + p;
*/

/*@
    lemma sum_nonnegative:
        \forall integer a, p;
        0 <= a <= 100 && 0 <= p <= 100 ==> compute_sum(a, p) >= 0;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= p <= 100;
    ensures \result >= 0;
    ensures \result <= a * 3 + p;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t p)
{
    int64_t sum;
    int64_t ret;
    int64_t temp_sum;
    int64_t count;

    //@ assert sum_in_range(a, p, a * 3 + p);
    sum = a * 3 + p;
    ret = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant sum_in_range(a, p, sum);
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
        //@ assert temp_sum == sum - 2 * count;
    }

    ret = count;
    //@ assert ret >= 0;
    //@ assert ret <= sum;
    return ret;
}
