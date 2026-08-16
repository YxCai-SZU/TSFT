#include <limits.h>

/*@
    predicate valid_range(integer v) = 0 <= v && v <= 10000;
    predicate ordered_pair(integer x, integer y) = x <= y;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    requires ordered_pair(a, b) && ordered_pair(c, d);
    ensures \result >= 0;
    ensures \result == b * d || \result == a * c || \result == a * d || \result == b * c;
*/
int func(int a, int b, int c, int d) {
    int max_val;
    int temp_val;

    //@ assert 0 <= a * c && a * c <= 10000 * 10000;
    max_val = a * c;

    //@ assert 0 <= a * d && a * d <= 10000 * 10000;
    temp_val = a * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert 0 <= b * c && b * c <= 10000 * 10000;
    temp_val = b * c;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    //@ assert 0 <= b * d && b * d <= 10000 * 10000;
    temp_val = b * d;
    if (temp_val > max_val) {
        max_val = temp_val;
    }

    return max_val;
}
