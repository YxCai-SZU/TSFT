#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b) =
        3 <= a && a <= 20 && 3 <= b && b <= 20;

    predicate possible_result(integer result, integer a, integer b) =
        result == 2 * a || result == 2 * b ||
        result == 2 * a - 1 || result == 2 * b - 1;
*/

/*@
    requires valid_input(a, b);
    ensures \result >= 0;
    ensures possible_result(\result, a, b);
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at scope top
    size_t result;

    if (a == b)
    {
        //@ assert a == b;
        result = 2 * a;
    }
    else
    {
        //@ assert a > b || b > a;
        if (a > b)
        {
            result = a * 2 - 1;
        }
        else
        {
            result = b * 2 - 1;
        }
    }

    //@ assert result >= 0;
    //@ assert possible_result(result, a, b);
    return result;
}
