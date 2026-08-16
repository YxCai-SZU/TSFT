#include <stdint.h>

/*@
    predicate is_valid_input(integer n) =
        100 <= n && n <= 999;

    logic integer div_by_3(integer n) = n / 3;
*/

/*@
    requires is_valid_input(n);
    ensures \result == div_by_3(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t result;
    //@ assert is_valid_input(n);
    result = n / 3;
    //@ assert result == div_by_3(n);
    return result;
}
