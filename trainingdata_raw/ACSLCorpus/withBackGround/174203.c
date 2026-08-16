#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == (c - b == b - a);
*/
bool func(int a, int b, int c) {
    // Variable declarations at scope top
    bool result;

    //@ assert a == (int)a;
    //@ assert b == (int)b;
    //@ assert c == (int)c;

    result = (c - b == b - a);
    return result;
}
