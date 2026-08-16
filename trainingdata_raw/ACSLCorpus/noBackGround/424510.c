#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    //@ assert (1 <= (a) <= 10000);
    uint32_t min_ab;
    uint32_t min_cd;
    uint32_t ans;

    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert ((a) < (b) ? (a) : (b)) <= 10000;
    //@ assert ((c) < (d) ? (c) : (d)) <= 10000;

    //@ assert ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d)) <= 20000;

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    ans = min_ab + min_cd;
    //@ assert ans == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    return ans;
}
