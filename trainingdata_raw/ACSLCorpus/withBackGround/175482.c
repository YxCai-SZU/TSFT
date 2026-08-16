/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer count_matches(integer a, integer b, integer c) =
        (a == b && a != c ? 1 : 0) +
        (a == c && a != b ? 1 : 0) +
        (b == c && a != b ? 1 : 0);

    lemma ans_range:
        \forall integer a, b, c, ans;
        is_valid_range(a) && is_valid_range(b) && is_valid_range(c) &&
        ans == count_matches(a, b, c) ==>
        0 <= ans <= 3;
*/

#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == ((a == b && b != c) || (a == c && c != b) || (b == c && a != b));
*/
bool func(int a, int b, int c)
{
    int ans = 0;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);

    if (a == b && a != c)
    {
        ans += 1;
    }

    if (a == c && a != b)
    {
        ans += 1;
    }

    if (b == c && a != b)
    {
        ans += 1;
    }

    //@ assert ans == count_matches(a, b, c);
    //@ assert 0 <= ans <= 3;

    return ans == 1;
}
