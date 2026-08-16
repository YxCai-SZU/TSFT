#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (((a) >= (c) && (a) - (c) < (d)) ||
        ((b) >= (c) && (b) - (c) < (d)) ||
        ((a) <= (b) && (a) + (d) >= (b)));
 */
bool func(unsigned long long a, unsigned long long b,
          unsigned long long c, unsigned long long d)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;

    if (a >= c && a - c < d) {
        //@ assert (((a) >= (c) && (a) - (c) < (d)) ||         ((b) >= (c) && (b) - (c) < (d)) ||         ((a) <= (b) && (a) + (d) >= (b)));
        result = true;
    } else if (b >= c && b - c < d) {
        //@ assert (((a) >= (c) && (a) - (c) < (d)) ||         ((b) >= (c) && (b) - (c) < (d)) ||         ((a) <= (b) && (a) + (d) >= (b)));
        result = true;
    } else if (a <= b && a + d >= b) {
        //@ assert (((a) >= (c) && (a) - (c) < (d)) ||         ((b) >= (c) && (b) - (c) < (d)) ||         ((a) <= (b) && (a) + (d) >= (b)));
        result = true;
    } else {
        //@ assert !(((a) >= (c) && (a) - (c) < (d)) ||         ((b) >= (c) && (b) - (c) < (d)) ||         ((a) <= (b) && (a) + (d) >= (b)));
        result = false;
    }

    return result;
}
