#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer sum_val(integer a, integer b) = a + b;

    logic integer result_val(integer a, integer b) = (a + b + 1) / 2;
*/

/*@
    requires valid_input(a, b);
    ensures \result == result_val(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t avg;
    uint32_t temp_sum;
    uint32_t count;

    sum = a + b;
    avg = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum / 2;
        loop invariant sum == a + b;
        loop invariant temp_sum + 2 * count == sum;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    avg = count;

    if (temp_sum == 1)
    {
        avg += 1;
    }

    //@ assert avg == result_val(a, b);
    return (int32_t)avg;
}
