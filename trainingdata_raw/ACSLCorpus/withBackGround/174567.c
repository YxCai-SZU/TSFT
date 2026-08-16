#include <stdbool.h>

/*@
    predicate diff_cond(integer a, integer b, integer c, integer d) =
        (a < c && b > d) || (a > c && b < d);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> diff_cond(a, b, c, d);
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int diff1;
    unsigned int diff2;
    bool result;

    if (a > c) {
        diff1 = a - c;
    } else {
        diff1 = c - a;
    }

    if (b > d) {
        diff2 = b - d;
    } else {
        diff2 = d - b;
    }

    if ((a < c && b > d) || (a > c && b < d)) {
        result = true;
        //@ assert diff_cond(a, b, c, d);
        return result;
    } else {
        if (diff1 > diff2) {
            //@ assert !diff_cond(a, b, c, d);
            result = false;
            return result;
        } else {
            //@ assert !diff_cond(a, b, c, d);
            result = false;
            return result;
        }
    }
}
