#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123 && 0 <= (b) <= 123 && 0 <= (c) <= 123 &&
        0 <= (d) <= 123 && 0 <= (e) <= 123 && 0 <= (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff;

    //@ assert a <= e;
    //@ assert e - a <= 123;

    if (a > e) {
        diff = a - e;
    } else {
        diff = e - a;
    }

    //@ assert diff == e - a;

    return diff <= k;
}
