#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer scaled_value(integer r) = r * 2 * 31415;

    logic integer expected_circumference(integer r) = (2 * 31415 * r) / 10000;

    lemma division_property:
        \forall integer r;
        valid_range(r) ==>
        expected_circumference(r) * 10000 <= scaled_value(r) &&
        scaled_value(r) < (expected_circumference(r) + 1) * 10000;
*/

/*@
    requires valid_range(r);
    ensures \result == (2 * 31415 * r) / 10000;
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scaled_r;
    int circumference;
    int temp;
    int divisor;

    pi_approx = 31415;
    scaled_r = r * 2 * pi_approx;
    circumference = 0;
    temp = scaled_r;
    divisor = 10000;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant 0 <= circumference;
        loop invariant 0 <= temp;
        loop invariant temp + circumference * divisor == scaled_r;
        loop invariant circumference * divisor <= 2 * 31415 * 100;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        //@ assert temp + circumference * divisor == scaled_r;
        circumference += 1;
        temp -= divisor;
        //@ assert temp + circumference * divisor == scaled_r;
    }

    //@ assert circumference == (2 * 31415 * r) / 10000;
    return circumference;
}
