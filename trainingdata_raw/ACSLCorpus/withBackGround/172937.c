#include <limits.h>

/*@
    predicate is_in_range(integer v) = 3 <= v && v <= 20;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result >= 0;
    ensures \result == a * 2 || \result == b * 2 || \result == a * 2 - 1 || \result == b * 2 - 1;
*/
int func(int a, int b)
{
    int min_a_b;
    int result;

    if (a < b) {
        min_a_b = a;
    } else {
        min_a_b = b;
    }

    result = min_a_b * 2 - 1;

    if (result >= 0) {
        //@ assert result == a * 2 - 1 || result == b * 2 - 1;
        return result;
    } else {
        return 0;
    }
}
