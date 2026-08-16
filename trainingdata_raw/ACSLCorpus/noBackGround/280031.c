#include <stdint.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10) && (1 <= (d) <= 10);
    ensures \result <= 1000;
    ensures \result == ((a) * (c)) || \result == ((a) * (d)) || 
            \result == ((b) * (c)) || \result == ((b) * (d));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
    uint32_t max_val;

    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert (1 <= (d) <= 10);

    x = a * c;
    y = a * d;
    z = b * c;
    w = b * d;

    //@ assert ((a) * (c)) <= 100;
    //@ assert ((a) * (d)) <= 100;
    //@ assert ((b) * (c)) <= 100;
    //@ assert ((b) * (d)) <= 100;

    max_val = x;
    if (y > max_val) {
        max_val = y;
    }
    if (z > max_val) {
        max_val = z;
    }
    if (w > max_val) {
        max_val = w;
    }

    //@ assert max_val <= 1000;
    //@ assert max_val == ((a) * (c)) || max_val == ((a) * (d)) || max_val == ((b) * (c)) || max_val == ((b) * (d));

    return max_val;
}
