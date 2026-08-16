#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 10;
    logic integer compute_result(integer x) = x + x * x + x * x * x;
*/

/*@
    requires is_valid_x(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t a1;
    int32_t a2;
    int32_t a3;
    int32_t result;

    //@ assert 1 <= x && x <= 10;
    //@ assert x * x <= 100;
    //@ assert x * x * x <= 1000;

    a1 = x;
    a2 = x * x;
    a3 = x * x * x;
    result = a1 + a2 + a3;

    //@ assert result == compute_result(x);
    return result;
}
