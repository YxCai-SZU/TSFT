#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 20;
    predicate b_in_range(integer b) = 1 <= b <= 20;
    predicate both_small(integer a, integer b) = a < 10 && b < 10;
    predicate one_large(integer a, integer b) = a >= 10 || b >= 10;
    logic integer func_result(integer a, integer b) =
        (a < 10 && b < 10) ? a * b : -1;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == func_result(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;

    if (a < 10 && b < 10)
    {
        //@ assert 1 <= a <= 9;
        result = a * b;
    }
    else
    {
        result = -1;
    }

    return result;
}
