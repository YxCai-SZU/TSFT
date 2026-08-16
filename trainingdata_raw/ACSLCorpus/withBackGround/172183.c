#include <stdint.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    predicate no_overflow(integer cost, integer sale) = 
        sale - cost <= 0x8000000000000000;
*/

/*@
    requires non_negative(actual_cost);
    requires non_negative(sale_amount);
    requires no_overflow(actual_cost, sale_amount);
    ensures \result == sale_amount - actual_cost;
    assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert sale_amount >= 0 && sale_amount <= 0x7FFFFFFFFFFFFFFF;
    //@ assert actual_cost >= 0 && actual_cost <= 0x7FFFFFFFFFFFFFFF;
    //@ assert sale_amount - actual_cost <= 0x8000000000000000;
    
    result = sale_amount - actual_cost;
    return result;
}
