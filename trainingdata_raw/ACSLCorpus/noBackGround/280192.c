#include <stdbool.h>

/*@
    requires ((a) >= 0 && (a) <= 123 &&
        (b) >= 0 && (b) <= 123 &&
        (c) >= 0 && (c) <= 123 &&
        (d) >= 0 && (d) <= 123 &&
        (e) >= 0 && (e) <= 123 &&
        (k) >= 0 && (k) <= 123);
    ensures \result == (k >= ((a) + (b) + (c) + (d) + (e)));
*/
bool func(long a, long b, long c, long d, long e, long k)
{
    long x;

    // Variable declarations at scope top
    x = a;

    //@ assert x == a;
    x = (x < b) ? (x + b) : (b + x);
    //@ assert x == a + b;
    x = (x < c) ? (x + c) : (c + x);
    //@ assert x == a + b + c;
    x = (x < d) ? (x + d) : (d + x);
    //@ assert x == a + b + c + d;
    x = (x < e) ? (x + e) : (e + x);
    //@ assert x == ((a) + (b) + (c) + (d) + (e));

    return k >= x;
}
