#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = a > -2147483648 && a < 2147483647;
    predicate b_in_range(integer b) = b > -2147483648 && b < 2147483647;
    predicate c_in_range(integer c) = c > -2147483648 && c < 2147483647;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    requires c_in_range(c);
    ensures \result == (a < b && b < c);
*/
bool func(int a, int b, int c)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert c_in_range(c);
    return a < b && b < c;
}
