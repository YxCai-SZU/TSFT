#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires a == (int64_t)a && b == (int64_t)b;
    ensures \result == ((a) - ((b) * 2)) || \result == 0;
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t x;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    x = a - (b * 2);
    //@ assert x == ((a) - ((b) * 2));
    if (x > 0) {
        //@ assert x == ((a) - ((b) * 2)) && x > 0;
        return x;
    } else {
        //@ assert x <= 0;
        return 0;
    }
}
