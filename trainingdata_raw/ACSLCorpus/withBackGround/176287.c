#include <stdbool.h>

/*@
    predicate is_between(integer a, integer b, integer c) =
        (a < c && c < b) || (b < c && c < a);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> is_between(a, b, c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int x;
    int y;

    if (a > b) {
        x = b;
        y = a;
    } else {
        x = a;
        y = b;
    }

    //@ assert 1 <= x <= 100 && 1 <= y <= 100;
    //@ assert x <= y;

    return c > x && c < y;
}
