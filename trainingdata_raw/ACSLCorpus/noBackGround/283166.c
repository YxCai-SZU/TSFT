#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((2 * (r) * 314) / 100);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t scale;
    int64_t numerator;
    int64_t denominator;
    int64_t quotient;
    int64_t remainder;

    pi_approx = 314;
    scale = 100;
    numerator = 2 * r * pi_approx;
    denominator = scale;
    quotient = 0;
    remainder = numerator;

    //@ assert 0 <= 2 * r * pi_approx <= 2 * 100 * 314;

    /*@
        loop invariant (1 <= (r) <= 100);
        loop invariant pi_approx == 314;
        loop invariant scale == 100;
        loop invariant numerator == 2 * r * pi_approx;
        loop invariant denominator == scale;
        loop invariant quotient * scale + remainder == numerator;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= denominator)
    {
        remainder -= denominator;
        quotient += 1;
    }

    //@ assert quotient * scale + remainder == numerator;
    //@ assert quotient == ((2 * (r) * 314) / 100);

    return quotient;
}

int main(void)
{
    return 0;
}
