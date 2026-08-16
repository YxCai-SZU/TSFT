#include <stdbool.h>

/*@
    predicate is_valid_int(long long x) =
        x >= -9223372036854775808 && x <= 9223372036854775807;
*/

/*@
    requires is_valid_int(actual_cost);
    requires is_valid_int(sale_amount);
    ensures \result == (actual_cost == sale_amount);
    assigns \nothing;
*/
bool noprofit_noloss(long long actual_cost, long long sale_amount)
{
    //@ assert is_valid_int(actual_cost);
    //@ assert is_valid_int(sale_amount);
    return actual_cost == sale_amount;
}
