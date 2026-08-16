#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 9; */

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (((b * 10 + c) - a) >= 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int bc;
    unsigned int max_val;
    unsigned int diff;
    unsigned int tmp_diff;

    bc = b * 10 + c;

    //@ assert bc == b * 10 + c;

    if (a > bc) {
        max_val = a;
    } else {
        max_val = bc;
    }

    //@ assert max_val == (a > bc ? a : bc);

    diff = max_val - bc;

    //@ assert diff == max_val - bc;

    if (a > bc) {
        tmp_diff = a - bc;
    } else {
        tmp_diff = bc - a;
    }

    //@ assert tmp_diff == (a > bc ? a - bc : bc - a);

    diff = tmp_diff;

    //@ assert diff == (a > bc ? a - bc : bc - a);

    return diff >= 0;
}
