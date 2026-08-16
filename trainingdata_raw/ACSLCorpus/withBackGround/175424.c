#include <stdint.h>

/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
*/

/*@
    logic integer expected_result(integer n) = (n - 2) * 180;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    //@ assert valid_n(n);
    result = ((int32_t)n - 2) * 180;
    //@ assert result == expected_result(n);
    return result;
}
