#include <limits.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        -1000 <= a <= 1000 &&
        -1000 <= b <= 1000 &&
        -1000 <= c <= 1000 &&
        -1000 <= d <= 1000 &&
        a <= b &&
        c <= d;

    logic integer product_bounds(integer x, integer y) = x * y;

    lemma product_bounds_lemma:
        \forall integer a, b, c, d;
            bounds(a, b, c, d) ==>
            -1000000 <= product_bounds(a, c) <= 1000000 &&
            -1000000 <= product_bounds(a, d) <= 1000000 &&
            -1000000 <= product_bounds(b, c) <= 1000000 &&
            -1000000 <= product_bounds(b, d) <= 1000000;
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int ans;

    //@ assert bounds(a, b, c, d);
    //@ assert -1000000 <= a * c <= 1000000;
    //@ assert -1000000 <= a * d <= 1000000;
    //@ assert -1000000 <= b * c <= 1000000;
    //@ assert -1000000 <= b * d <= 1000000;

    if (a * c > a * d)
        x = a * c;
    else
        x = a * d;

    if (b * c > b * d)
        y = b * c;
    else
        y = b * d;

    if (x > y)
        ans = x;
    else
        ans = y;

    //@ assert ans == b * d || ans == b * c || ans == a * d || ans == a * c;
    return ans;
}
