#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer condition_formula(integer a, integer b, integer c) =
        (a == b && a != c ? 1 : 0) +
        (b == c && b != a ? 1 : 0) +
        (c == a && c != b ? 1 : 0);
 */

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    ensures \result == (condition_formula(a, b, c) > 0);
 */
bool func(int a, int b, int c)
{
    bool ans;

    ans = false;

    if (a == b && a != c) {
        ans = true;
    } else if (b == c && b != a) {
        ans = true;
    } else if (c == a && c != b) {
        ans = true;
    }

    //@ assert ans == (condition_formula(a, b, c) > 0);

    return ans;
}
