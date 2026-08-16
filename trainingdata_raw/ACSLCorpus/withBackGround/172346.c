#include <limits.h>

/*@
    predicate scaled_value_in_range(integer r, integer sv) =
        1 <= r <= 100 && sv == r * 2 * 3142;

    logic integer compute_expected(integer r) = 
        (2 * r * 3142) / 1000;

    lemma scaled_value_bounds: 
        \forall integer r; 1 <= r <= 100 ==> 0 <= r * 2 * 3142 <= 628400;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == (2 * r * 3142) / 1000;
    assigns \nothing;
*/
int func(int r) {
    int pi_approx;
    int scaled_value;
    int divisor;
    int quotient;
    int remainder;
    int scaled_value_abs;

    pi_approx = 3142;
    scaled_value = r * 2 * pi_approx;
    divisor = 1000;
    quotient = 0;

    //@ assert scaled_value_in_range(r, scaled_value);

    if (scaled_value < 0) {
        scaled_value_abs = -scaled_value;
    } else {
        scaled_value_abs = scaled_value;
    }
    remainder = scaled_value_abs;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant divisor == 1000;
        loop invariant quotient >= 0;
        loop invariant scaled_value == r * 2 * pi_approx;
        loop invariant scaled_value < 0 ==> remainder == -scaled_value - quotient * divisor;
        loop invariant scaled_value >= 0 ==> remainder == scaled_value - quotient * divisor;
        loop invariant 0 <= remainder < divisor + scaled_value_abs;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder = remainder - divisor;
        quotient = quotient + 1;
    }

    if (scaled_value < 0) {
        quotient = -quotient;
    }

    //@ assert quotient == compute_expected(r);
    return quotient;
}

int main() {
    return 0;
}
