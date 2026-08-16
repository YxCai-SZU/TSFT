#include <limits.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result >= 0;
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
long func(long x) {
    long x_abs;
    long quotient_500;
    long remainder_500;
    long quotient_5;
    long remainder_5;
    long result;

    x_abs = (x < 0) ? -x : x;

    quotient_500 = 0;
    remainder_500 = x_abs;

    /*@
        loop invariant 0 <= remainder_500 <= x_abs;
        loop invariant 0 <= quotient_500 <= ((x_abs) / 500);
        loop invariant remainder_500 == x_abs - quotient_500 * 500;
        loop assigns quotient_500, remainder_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500) {
        //@ assert remainder_500 >= 500;
        quotient_500 = quotient_500 + 1;
        remainder_500 = remainder_500 - 500;
        //@ assert remainder_500 == x_abs - quotient_500 * 500;
    }

    quotient_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant 0 <= remainder_5 <= remainder_500;
        loop invariant 0 <= quotient_5 <= (((remainder_500) % 500) / 5);
        loop invariant remainder_5 == remainder_500 - quotient_5 * 5;
        loop assigns quotient_5, remainder_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5) {
        //@ assert remainder_5 >= 5;
        quotient_5 = quotient_5 + 1;
        remainder_5 = remainder_5 - 5;
        //@ assert remainder_5 == remainder_500 - quotient_5 * 5;
    }

    result = quotient_500 * 1000 + quotient_5 * 5;
    //@ assert result == (((x_abs) / 500) * 1000 + (((x_abs) % 500) / 5) * 5);
    return result;
}

int main() {
    return 0;
}
