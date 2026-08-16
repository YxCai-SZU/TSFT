#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer pi_approx = 3141592653589793;
    logic integer divisor = 1000000000000000;

    logic integer expected_circumference(integer r) =
        (2 * pi_approx * r) / divisor;

    lemma division_property:
        \forall integer r, integer c, integer t;
            valid_range(r) ==>
            c * divisor + t == 2 * pi_approx * r ==>
            0 <= t < divisor ==>
            c == expected_circumference(r);
*/

/*@
    requires valid_range(r);
    ensures \result >= 0;
    ensures \result == expected_circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r) {
    int64_t pi_approx;
    int64_t circumference;
    int64_t temp;
    int64_t divisor;

    pi_approx = 3141592653589793;
    circumference = 0;
    temp = 2 * pi_approx * r;
    divisor = 1000000000000000;

    /*@
        loop invariant valid_range(r);
        loop invariant pi_approx == 3141592653589793;
        loop invariant divisor == 1000000000000000;
        loop invariant temp >= 0;
        loop invariant circumference * divisor + temp == 2 * pi_approx * r;
        loop assigns circumference, temp;
        loop variant temp;
    */
    while (temp >= divisor) {
        temp -= divisor;
        circumference += 1;
    }

    //@ assert 0 <= temp < divisor;
    //@ assert circumference == expected_circumference(r);

    return circumference;
}
