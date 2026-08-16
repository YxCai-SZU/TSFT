#include <stdint.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && b == c;

    predicate two_equal(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && a != b);

    predicate all_different(integer a, integer b, integer c) =
        a != b && b != c && a != c;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> a == b && b == c;
    ensures \result == 2 ==> (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
    ensures \result == 3 ==> a != b && b != c && a != c;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t result;

    if (a == b && b == c)
    {
        //@ assert a == b && b == c;
        result = 1;
    }
    else if (a == b || a == c || b == c)
    {
        //@ assert (a == b && a != c) || (a == c && a != b) || (b == c && a != b);
        result = 2;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = 3;
    }

    return result;
}
