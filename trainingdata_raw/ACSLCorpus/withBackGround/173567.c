#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 10;

    logic integer sum_plus_one(integer a, integer b, integer c) = a + b + c + 1;

    lemma subtraction_bound: \forall integer a, c; a + c >= 1 ==> a + c - 1 <= a + c;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result <= sum_plus_one(a, b, c);
    ensures \result >= b;
*/
uintptr_t func(uintptr_t a, uintptr_t b, uintptr_t c)
{
    uintptr_t result;
    result = b;

    if (a + c >= 1)
    {
        uintptr_t temp;
        /*@ assert a + c - 1 <= a + c; */
        if (a + c - 1 < a + c)
        {
            temp = a + c - 1;
        }
        else
        {
            temp = a + c;
        }
        result += temp;
    }

    return result;
}
