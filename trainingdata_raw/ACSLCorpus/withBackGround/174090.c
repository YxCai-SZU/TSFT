#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100 &&
        a * b <= 9223372036854775807 && a * b >= -9223372036854775808;

    logic integer multiply(integer a, integer b) = a * b;
*/

/*@
    requires valid_range(a, b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert a * b <= 9223372036854775807;
    //@ assert a * b >= -9223372036854775808;

    result = a * b;
    return result;
}
