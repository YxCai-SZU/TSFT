#include <stdbool.h>

/*@
    predicate is_less_than(integer a, integer b) = a < b;
    predicate is_between(integer a, integer b, integer c) = 
        is_less_than(a, b) && is_less_than(b, c);
*/

/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    requires c < 0x80000000;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int i;
    bool result;

    i = a;
    result = true;

    //@ assert i == a;

    if (i < b && b < c) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a < b && b < c);

    return result;
}
