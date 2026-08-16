#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;

    logic integer safe_product(integer a, integer b) =
        a * b;

    predicate both_small(integer a, integer b) =
        a <= 9 && b <= 9;

    predicate one_large(integer a, integer b) =
        a > 9 || b > 9;
*/

/*@
    requires valid_range(a, b);
    ensures both_small(a, b) ==> \result == safe_product(a, b);
    ensures one_large(a, b) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top
    int32_t result;

    if (a <= 9 && b <= 9)
    {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert safe_product(a, b) <= 81;
        result = (int32_t)(a * b);
    }
    else
    {
        result = -1;
    }

    return result;
}
