#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c - a >= b && c - a <= c);
*/
bool func(int a, int b, int c) {
    int d;
    int e;
    bool result;

    d = c - a;
    e = c - d;

    //@ assert d == c - a;
    //@ assert e == c - d;

    result = d >= b && d <= c && e >= 0;
    return result;
}
