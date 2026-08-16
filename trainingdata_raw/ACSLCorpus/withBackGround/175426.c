#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 100; */

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(long a, long b, long c) {
    long diff1;
    long diff2;
    bool result;

    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);

    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == b - a;
    //@ assert diff2 == c - b;

    //@ assert diff1 == diff2 || diff1 != diff2;

    result = (diff1 == diff2);
    return result;
}
