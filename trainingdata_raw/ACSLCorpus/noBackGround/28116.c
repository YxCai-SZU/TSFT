#include <stdint.h>

/*@
    requires ((actual_cost) >= -(9223372036854775) && (actual_cost) <= 9223372036854775 &&
        (sale_amount) >= -(9223372036854775) && (sale_amount) <= 9223372036854775);
    ensures \result == ((sale_amount) - (actual_cost));
    ensures \result >= -9223372036854775807 && \result <= 9223372036854775807;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    
    //@ assert sale_amount >= -(9223372036854775);
    //@ assert sale_amount <= 9223372036854775;
    //@ assert actual_cost >= -(9223372036854775);
    //@ assert actual_cost <= 9223372036854775;
    
    ret = sale_amount - actual_cost;
    
    //@ assert ret == ((sale_amount) - (actual_cost));
    //@ assert ret >= -9223372036854775807 && ret <= 9223372036854775807;
    
    return ret;
}
