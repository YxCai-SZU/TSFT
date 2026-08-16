#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000 &&
        (d) % 1 == 0 &&
        (t) % 1 == 0 &&
        (s) % 1 == 0);
    ensures \result == (t * s >= d);
*/
bool func(int d, int t, int s)
{
    int max_val;
    int min_val;
    bool result;

    //@ assert (1 <= (d) <= 10000 &&         1 <= (t) <= 10000 &&         1 <= (s) <= 10000 &&         (d) % 1 == 0 &&         (t) % 1 == 0 &&         (s) % 1 == 0);

    // Calculate max_val
    if (t > s) {
        max_val = t;
    } else {
        max_val = s;
    }

    //@ assert max_val == (((t) > (s)) ? (t) : (s));
    //@ assert max_val >= 1 && max_val <= 10000;

    // Calculate min_val
    if (t < s) {
        min_val = t;
    } else {
        min_val = s;
    }

    //@ assert min_val == (((t) < (s)) ? (t) : (s));
    //@ assert min_val >= 1 && min_val <= 10000;

    //@ assert t * s <= 10000 * 10000;

    result = (t * s >= d);
    //@ assert result == (t * s >= d);
    return result;
}
