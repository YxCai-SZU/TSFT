#include <stdbool.h>

/*@ predicate is_within_i64_bounds(integer x) =
        x >= -0x8000000000000000 && x < 0x8000000000000000;
*/

/*@
    requires is_within_i64_bounds(actual_cost);
    requires is_within_i64_bounds(sale_amount);
    ensures \result == (sale_amount > actual_cost);
*/
bool has_profit(long long actual_cost, long long sale_amount)
{
    //@ assert is_within_i64_bounds(sale_amount);
    //@ assert is_within_i64_bounds(actual_cost);
    return sale_amount > actual_cost;
}
