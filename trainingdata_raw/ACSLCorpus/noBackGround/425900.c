#include <stdint.h>

/*@
    requires 0 <= a <= 10000;
    requires 0 <= b <= 10000;
    requires 0 <= c <= 10000;
    requires 0 <= d <= 10000;
    ensures \result >= 0;
    ensures \result == ((a) > (b) ? (a) - (b) : 0) ||
            \result == ((b) - (a) > (c) ? (b) - (a) - (c) : 0) ||
            \result == ((c) > (d) ? (c) - (d) : 0);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t y;
    int64_t z;
    int64_t max_val;

    x = a > b ? a - b : 0;
    y = b - a > c ? b - a - c : 0;
    z = c > d ? c - d : 0;

    max_val = x;
    //@ assert max_val == ((a) > (b) ? (a) - (b) : 0);
    if (y > max_val)
    {
        max_val = y;
    }
    //@ assert max_val == ((a) > (b) ? (a) - (b) : 0) || max_val == ((b) - (a) > (c) ? (b) - (a) - (c) : 0);
    if (z > max_val)
    {
        max_val = z;
    }
    //@ assert max_val == ((a) > (b) ? (a) - (b) : 0) || max_val == ((b) - (a) > (c) ? (b) - (a) - (c) : 0) || max_val == ((c) > (d) ? (c) - (d) : 0);
    //@ assert ((max_val) >= 0);

    return max_val;
}
