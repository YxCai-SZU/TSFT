#include <limits.h>

/*@
    predicate is_min(integer x, integer a, integer b, integer c) =
        x == a || x == b || x == c &&
        x <= a && x <= b && x <= c;
*/


int min_numbers(int a, int b, int c) {
    // Variable declarations at top of scope
    int ret;

    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;

    if (a <= b && a <= c) {
        //@ assert a <= b && a <= c;
        ret = a;
    } else if (b <= a && b <= c) {
        //@ assert b <= a && b <= c;
        ret = b;
    } else {
        ret = c;
    }

    //@ assert is_min(ret, a, b, c);
    return ret;
}
