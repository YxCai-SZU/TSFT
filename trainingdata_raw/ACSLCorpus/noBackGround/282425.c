#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == 1000 * (x / 500) + 5 * ((x - 500 * (x / 500)) / 5);
*/
int64_t func(int64_t x) {
    int64_t quotient;
    int64_t remainder;
    int64_t five_hundreds;
    int64_t five;
    int64_t ans;

    quotient = 0;
    remainder = x;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x / 500;
        loop invariant remainder == x - 500 * quotient;
        loop invariant 0 <= x <= 1000000000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 500) {
        //@ assert remainder >= 500;
        quotient = quotient + 1;
        remainder = remainder - 500;
    }

    five_hundreds = quotient * 1000;

    quotient = 0;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= (x - 500 * (x / 500)) / 5;
        loop invariant remainder == (x - 500 * (x / 500)) - 5 * quotient;
        loop invariant 0 <= x <= 1000000000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 5) {
        //@ assert remainder >= 5;
        quotient = quotient + 1;
        remainder = remainder - 5;
    }

    five = quotient * 5;
    ans = five_hundreds + five;

    //@ assert ans == 1000 * (x / 500) + 5 * ((x - 500 * (x / 500)) / 5);
    return ans;
}
