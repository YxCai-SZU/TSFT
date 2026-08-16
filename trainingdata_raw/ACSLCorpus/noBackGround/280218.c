#include <stdint.h>
/*@
    requires (1 <= (a) <= 1000000000) && (1 <= (b) <= 1000000000) && (1 <= (c) <= 1000000000) && (1 <= (d) <= 1000000000);
    ensures \result >= 0;
    ensures \result == ((a) * (b)) || \result == ((c) * (d)) ||
            \result == ((a) * (d)) || \result == ((b) * (c));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    //@ assert (1 <= (a) <= 1000000000);
    //@ assert (1 <= (b) <= 1000000000);
    //@ assert (1 <= (c) <= 1000000000);
    //@ assert (1 <= (d) <= 1000000000);
    
    //@ assert ((a) * (b)) <= 9223372036854775807;
    //@ assert ((c) * (d)) <= 9223372036854775807;
    //@ assert ((a) * (d)) <= 9223372036854775807;
    //@ assert ((b) * (c)) <= 9223372036854775807;

    int64_t x = a * b;
    int64_t y = c * d;
    int64_t z = a * d;
    int64_t w = b * c;
    int64_t max_val;

    if (x > y) {
        if (x > z) {
            if (x > w) {
                max_val = x;
            } else {
                max_val = w;
            }
        } else {
            if (z > w) {
                max_val = z;
            } else {
                max_val = w;
            }
        }
    } else {
        if (y > z) {
            if (y > w) {
                max_val = y;
            } else {
                max_val = w;
            }
        } else {
            if (z > w) {
                max_val = z;
            } else {
                max_val = w;
            }
        }
    }

    //@ assert max_val >= 0;
    return max_val;
}
