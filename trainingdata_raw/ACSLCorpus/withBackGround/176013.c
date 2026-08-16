#include <stdbool.h>

/*@
    predicate is_sum_possible(integer a, integer b, integer c) =
        (a + b == c) || (b + c == a) || (a + c == b);
 */

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == true <==> is_sum_possible(a, b, c);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result = false;

    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    if (a + b == c)
    {
        result = true;
    }

    if (b + c == a)
    {
        result = true;
    }

    if (a + c == b)
    {
        result = true;
    }

    //@ assert result == true <==> is_sum_possible(a, b, c);

    return result;
}
