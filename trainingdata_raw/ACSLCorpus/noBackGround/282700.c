#include <stdint.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result <= b * c || \result <= d * c || \result <= a * c || \result == a * b || \result == a * d || \result == b * d;
    ensures \result >= b * c || \result >= d * c || \result >= a * c || \result == a * b || \result == a * d || \result == b * d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t min_all;

    //@ assert (1 <= (a) <= 10000 &&         1 <= (b) <= 10000 &&         1 <= (c) <= 10000 &&         1 <= (d) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((b) * (c)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;
    //@ assert ((d) * (a)) <= 10000 * 10000;
    //@ assert ((a) * (c)) <= 10000 * 10000;
    //@ assert ((b) * (d)) <= 10000 * 10000;
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((b) * (c)) >= 1;
    //@ assert ((c) * (d)) >= 1;
    //@ assert ((d) * (a)) >= 1;
    //@ assert ((a) * (c)) >= 1;
    //@ assert ((b) * (d)) >= 1;

    if (a * b < b * c) {
        min_ab = a * b;
    } else {
        min_ab = b * c;
    }

    if (c * d < d * a) {
        min_cd = c * d;
    } else {
        min_cd = d * a;
    }

    if (min_ab < min_cd) {
        min_all = min_ab;
    } else {
        min_all = min_cd;
    }

    return min_all;
}
