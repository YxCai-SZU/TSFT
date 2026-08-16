#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result <= 20000;
    ensures \result == (((a) < (b)) ? (a) : (b)) + (((c) < (d)) ? (c) : (d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t min1;
    uint32_t min2;
    uint32_t sum;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a < b) {
        min1 = a;
    } else {
        min1 = b;
    }
    //@ assert min1 == (((a) < (b)) ? (a) : (b));

    if (c < d) {
        min2 = c;
    } else {
        min2 = d;
    }
    //@ assert min2 == (((c) < (d)) ? (c) : (d));

    sum = min1 + min2;
    //@ assert sum == (((a) < (b)) ? (a) : (b)) + (((c) < (d)) ? (c) : (d));
    //@ assert sum <= 20000;

    return sum;
}
