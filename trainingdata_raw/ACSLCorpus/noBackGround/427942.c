#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    requires (0 <= (x) <= 100);
    ensures \result == (x <= a + b && a <= x);
*/
bool func(long a, long b, long x)
{
    long min;
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert (0 <= (x) <= 100);

    if (a < x) {
        min = a;
    } else {
        min = x;
    }
    //@ assert min == (((a) < (x)) ? (a) : (x));
    //@ assert min == a || min == x;

    return x <= a + b && min == a;
}
