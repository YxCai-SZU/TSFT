#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a && a <= 500 &&
        1 <= b && b <= 500 &&
        1 <= c && c <= 1000;

    logic integer sum(integer a, integer b) = a + b;
*/

/*@
    requires is_valid_params(a, b, c);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    bool result;
    result = false;

    //@ assert a + b >= c ==> result == false;

    if (a + b >= c)
    {
        result = true;
    }

    //@ assert result == (a + b >= c);
    return result;
}
