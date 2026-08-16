#include <stdbool.h>

/*@
    predicate b_le_x(integer b, integer x) = b <= x;
    predicate a_ge_x_minus_b_plus_1(integer a, integer b, integer x) = a >= x - b + 1;
    predicate result_condition(integer a, integer b, integer x) =
        b_le_x(b, x) && a_ge_x_minus_b_plus_1(a, b, x);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= x <= 200;
    ensures \result == (b <= x && a >= x - b + 1);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    bool result;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= x <= 200;
    result = b <= x && a >= x - b + 1;
    //@ assert result == (b <= x && a >= x - b + 1);
    return result;
}
