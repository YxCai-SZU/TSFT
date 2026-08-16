#include <stdbool.h>

/*@
    requires (-1000000000 <= (a) && (a) <= 1000000000) && (-1000000000 <= (b) && (b) <= 1000000000) && (-1000000000 <= (c) && (c) <= 1000000000) && (-1000000000 <= (d) && (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == (a <= d && b >= c);
*/
bool func(long a, long b, long c, long d) {
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b && c <= d;

    result = (a <= d && b >= c);
    return result;
}
