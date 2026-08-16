#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c) =
        a <= b ==> (c >= a && c <= b);
*/

/*@
    requires a <= b;
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a <= b;
    return c >= a && c <= b;
}
