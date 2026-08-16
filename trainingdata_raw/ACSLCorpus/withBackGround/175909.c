#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate net_gain_condition(integer actual_cost, integer sale_amount, integer ret) =
        ret >= 0 && ret <= sale_amount && (ret == sale_amount - actual_cost || ret == 0);
*/

/*@
    requires non_negative(actual_cost) && non_negative(sale_amount);
    ensures net_gain_condition(actual_cost, sale_amount, \result);
    assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    //@ assert non_negative(actual_cost);
    //@ assert non_negative(sale_amount);
    
    if (sale_amount > actual_cost) {
        //@ assert sale_amount > actual_cost;
        //@ assert sale_amount >= actual_cost;
        ret = sale_amount - actual_cost;
    } else {
        ret = 0;
    }
    
    //@ assert ret >= 0;
    //@ assert ret <= sale_amount;
    //@ assert ret == sale_amount - actual_cost || ret == 0;
    return ret;
}
