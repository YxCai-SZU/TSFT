#include <stdbool.h>

/*@
    predicate is_sum_eq(integer a, integer b, integer c) =
        a + b == c || b + c == a || c + a == b;
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == true <==> is_sum_eq(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool ret = false;

    //@ assert 0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100;

    if (a + b == c)
    {
        ret = true;
    }

    if (b + c == a)
    {
        ret = true;
    }

    if (c + a == b)
    {
        ret = true;
    }

    //@ assert ret == true <==> is_sum_eq(a, b, c);

    return ret;
}
