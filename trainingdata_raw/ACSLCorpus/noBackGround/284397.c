#include <stdint.h>

/*@
    requires (((sale_amount) - (actual_cost)) >= INT64_MIN &&
        ((sale_amount) - (actual_cost)) <= INT64_MAX);
    ensures \result == ((sale_amount) - (actual_cost));
    assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    //@ assert (((sale_amount) - (actual_cost)) >= INT64_MIN &&         ((sale_amount) - (actual_cost)) <= INT64_MAX);
    
    int64_t ret;
    ret = sale_amount - actual_cost;
    
    //@ assert ret == ((sale_amount) - (actual_cost));
    return ret;
}
