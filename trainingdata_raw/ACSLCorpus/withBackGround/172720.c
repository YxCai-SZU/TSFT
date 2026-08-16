#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 100;

    logic integer compute_result(integer a) = a * 100 + 100;
*/

/*@
    requires valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t result;

    //@ assert a * 100 + 100 == a * 100 + 100;
    result = a * 100 + 100;
    return result;
}
