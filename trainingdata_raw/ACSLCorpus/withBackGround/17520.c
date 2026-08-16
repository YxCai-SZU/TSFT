#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 5000;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == ((a + b) >= c);
*/
bool func(long a, long b, long c) {
    long d;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    d = a + b;
    //@ assert d == a + b;
    return d >= c;
}
