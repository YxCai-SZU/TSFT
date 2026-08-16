#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        (a < b && b < c) || (a > b && b > c);
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    requires a != b && b != c && a != c;
    ensures \result == true <==> is_ordered(a, b, c);
 */
bool func(int a, int b, int c)
{
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;
    return (a < b && b < c) || (a > b && b > c);
}
