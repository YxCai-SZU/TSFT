#include <stdbool.h>

/*@
    predicate sum_lt(integer a, integer b, integer c, integer d) =
        a + c < b + d;
*/

/*@
    requires 0 <= a < 10;
    requires 0 <= b < 10;
    requires 0 <= c < 10;
    requires 0 <= d < 10;
    ensures \result == true <==> a + c < b + d;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result = false;
    //@ assert a + c < b + d <==> sum_lt(a, b, c, d);
    if (a + c < b + d)
    {
        result = true;
    }
    //@ assert result == true <==> sum_lt(a, b, c, d);
    return result;
}
