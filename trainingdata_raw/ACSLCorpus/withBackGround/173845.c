#include <stdbool.h>

/*@
    predicate is_valid_input(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer average_result(integer a, integer b) =
        (a + b) / 2;

    logic integer ceiling_result(integer a, integer b) =
        (a + b) / 2 + 1;

    lemma average_property:
        \forall integer a, b;
            is_valid_input(a, b) ==>
                (a + b) % 2 == 0 ==> average_result(a, b) == ceiling_result(a, b) - 1;

    lemma ceiling_property:
        \forall integer a, b;
            is_valid_input(a, b) ==>
                (a + b) % 2 == 1 ==> average_result(a, b) + 1 == ceiling_result(a, b);
*/

/*@
    requires is_valid_input(a, b);
    ensures \result == average_result(a, b) || \result == ceiling_result(a, b);
*/
int func(int a, int b)
{
    int sum;
    int average;
    bool is_odd;
    int temp_sum;

    sum = a + b;
    average = 0;
    is_odd = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant 0 <= average <= sum / 2;
        loop invariant temp_sum + 2 * average == sum;
        loop assigns temp_sum, average;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        average += 1;
    }

    //@ assert temp_sum == 0 || temp_sum == 1;
    if (temp_sum == 1)
    {
        is_odd = true;
    }

    //@ assert is_odd == (temp_sum == 1);
    if (is_odd)
    {
        average += 1;
    }

    //@ assert average == average_result(a, b) || average == ceiling_result(a, b);
    return average;
}
