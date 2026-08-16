#include <stdbool.h>

/*@
    predicate is_abs_diff(integer a, integer b, integer diff) =
        diff == (a >= b ? a - b : b - a);

    lemma abs_diff_symmetry:
        \forall integer a, b, d1, d2;
            is_abs_diff(a, b, d1) && is_abs_diff(b, a, d2) ==> d1 == d2;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == ((b - a == c - b) || (b - a == b - c) || (a - b == b - c));
*/
bool func(int a, int b, int c)
{
    int x;
    int y;

    x = b - a;
    y = c - b;

    //@ assert is_abs_diff(b, a, x >= 0 ? x : -x);
    if (x < 0)
    {
        x = -x;
    }
    //@ assert x >= 0;
    //@ assert is_abs_diff(b, a, x);

    //@ assert is_abs_diff(c, b, y >= 0 ? y : -y);
    if (y < 0)
    {
        y = -y;
    }
    //@ assert y >= 0;
    //@ assert is_abs_diff(c, b, y);

    //@ assert x == y ==> ((b - a == c - b) || (b - a == b - c) || (a - b == b - c));
    return x == y;
}
