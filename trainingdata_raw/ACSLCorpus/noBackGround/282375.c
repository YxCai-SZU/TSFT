#include <stdint.h>

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires a <= b;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires c <= d;
    requires -1000000000000000000 <= a * c <= 1000000000000000000;
    requires -1000000000000000000 <= a * d <= 1000000000000000000;
    requires -1000000000000000000 <= b * c <= 1000000000000000000;
    requires -1000000000000000000 <= b * d <= 1000000000000000000;
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t max_val;
    int64_t temp_val;

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    max_val = a * c;
    temp_val = a * d;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    temp_val = b * c;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }
    temp_val = b * d;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;
    return max_val;
}
