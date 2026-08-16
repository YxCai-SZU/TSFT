#include <stdint.h>

/*@
    predicate valid_i64_range(integer x) =
        x >= -9223372036854775808 && x <= 9223372036854775807;
*/

/*@
    logic integer net_gain_logic(integer actual_cost, integer sale_amount) =
        sale_amount - actual_cost;
*/

/*@
    lemma net_gain_bounds:
        \forall integer actual_cost, sale_amount;
            actual_cost >= 0 && sale_amount >= 0 &&
            valid_i64_range(actual_cost) && valid_i64_range(sale_amount) ==>
            valid_i64_range(sale_amount - actual_cost);
*/

/*@
    requires actual_cost >= 0 && sale_amount >= 0;
    requires valid_i64_range(actual_cost) && valid_i64_range(sale_amount);
    ensures \result == sale_amount - actual_cost;
    ensures valid_i64_range(\result);
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    //@ assert sale_amount - actual_cost >= -9223372036854775808;
    //@ assert sale_amount - actual_cost <= 9223372036854775807;
    
    return sale_amount - actual_cost;
}
