/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer scaled_pi(integer r) = 2 * r * 3142 / 1000;

    lemma loop1_invariant_maintained:
        \forall integer r, temp_r, circumference;
        valid_range(r) && 0 <= temp_r <= r && circumference == (r - temp_r) * 3142 ==>
        (temp_r > 0 ==> circumference + 3142 == (r - (temp_r - 1)) * 3142);

    lemma loop2_invariant_maintained:
        \forall integer r, result, circumference;
        valid_range(r) && 0 <= result && circumference >= 0 &&
        circumference == (r * 3142 * 2) - (result * 1000) ==>
        (circumference >= 1000 ==> circumference - 1000 == (r * 3142 * 2) - ((result + 1) * 1000));
*/

#include <stdint.h>

/*@
    requires valid_range(r);
    ensures \result == scaled_pi(r);
*/
int32_t func(int32_t r)
{
    // Variable declarations
    int32_t pi = 3142;
    int32_t two = 2;
    int32_t scale = 1000;
    int32_t circumference = 0;
    int32_t temp_r = r;
    int32_t temp_pi = pi;
    int32_t result = 0;

    // First loop: circumference = r * pi
    /*@
        loop invariant 0 <= temp_r <= r;
        loop invariant circumference == (r - temp_r) * pi;
        loop invariant pi == 3142;
        loop invariant two == 2;
        loop invariant scale == 1000;
        loop assigns circumference, temp_r;
    */
    while (temp_r > 0)
    {
        //@ assert temp_r > 0;
        circumference += temp_pi;
        temp_r -= 1;
    }

    circumference *= two;

    // Second loop: result = circumference / scale
    /*@
        loop invariant 0 <= result;
        loop invariant circumference >= 0;
        loop invariant circumference == (r * pi * two) - (result * scale);
        loop invariant pi == 3142;
        loop invariant two == 2;
        loop invariant scale == 1000;
        loop invariant result <= (r * pi * two) / scale;
        loop assigns circumference, result;
    */
    while (circumference >= scale)
    {
        //@ assert circumference >= scale;
        circumference -= scale;
        result += 1;
    }

    //@ assert result == scaled_pi(r);
    return result;
}
