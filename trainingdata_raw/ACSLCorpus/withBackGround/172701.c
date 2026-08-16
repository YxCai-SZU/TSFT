#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 20 && 1 <= b <= 20;
    
    logic integer expected_result(integer a, integer b) =
        (a + b + 1) / 2;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t half_sum;
    int64_t result;
    
    sum = a + b;
    half_sum = sum / 2;
    
    if (sum % 2 == 0) {
        //@ assert half_sum == (a + b + 1) / 2;
        result = (int64_t)half_sum;
    } else {
        result = (int64_t)(half_sum + 1);
    }
    
    return result;
}
