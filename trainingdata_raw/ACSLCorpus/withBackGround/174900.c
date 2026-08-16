#include <limits.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;

    logic integer manual_ceiling_div(integer a, integer b) = (a + b + 1) / 2;

    lemma division_property:
        \forall integer a, b, sum, count;
        valid_range(a) && valid_range(b) && sum == a + b &&
        0 <= count <= sum/2 ==> sum - 2*count >= 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == manual_ceiling_div(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int avg;
    int temp_sum;
    int count;

    sum = a + b;
    avg = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= count <= sum/2;
        loop invariant temp_sum == sum - 2*count;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    avg = count;

    if (temp_sum == 1)
    {
        //@ assert temp_sum == 1;
        avg += 1;
    }

    //@ assert avg == manual_ceiling_div(a, b);
    return avg;
}
