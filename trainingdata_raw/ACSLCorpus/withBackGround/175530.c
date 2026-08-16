#include <stdbool.h>

/*@
    predicate valid_input(int a, int b, int c) =
        1 <= a && a <= 5000 &&
        1 <= b && b <= 5000 &&
        1 <= c && c <= 5000;

    logic integer sum(integer a, integer b) = a + b;

    predicate is_triangle_sum(int a, int b, int c) =
        sum(a, b) == c || sum(b, c) == a || sum(a, c) == b;
*/

/*@
    requires valid_input(v0, v1, v2);
    ensures \result <==> is_triangle_sum(v0, v1, v2);
    assigns \nothing;
*/
bool func(int v0, int v1, int v2)
{
    //@ assert valid_input(v0, v1, v2);
    return (v0 + v1 == v2) || (v1 + v2 == v0) || (v0 + v2 == v1);
}
