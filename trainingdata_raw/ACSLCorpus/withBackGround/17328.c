#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer condition(integer a, integer b, integer c) =
        ((a == b && a != c) || (a != b && a == c) || (a != b && b == c)) ? 1 : 0;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == condition(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool ans = false;

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;

    if ((a == b && a != c) || (a != b && a == c) || (a != b && b == c)) {
        ans = true;
    }

    //@ assert ans == (condition(a, b, c) == 1);
    return ans;
}
