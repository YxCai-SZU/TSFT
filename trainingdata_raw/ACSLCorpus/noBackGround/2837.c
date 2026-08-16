#include <stdint.h>

/*@
    requires ((actual_cost) > 0 && (sale_amount) >= 0);
    ensures ((\result) >= 0 && (\result) <= (actual_cost));
    assigns \nothing;
*/
int64_t discount_amount(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    //@ assert ((actual_cost) > 0 && (sale_amount) >= 0);
    
    if (actual_cost > sale_amount)
    {
        //@ assert actual_cost > sale_amount;
        ret = actual_cost - sale_amount;
        //@ assert ret >= 0;
        //@ assert ret <= actual_cost;
    }
    else
    {
        //@ assert actual_cost <= sale_amount;
        ret = 0;
        //@ assert ret >= 0;
        //@ assert ret <= actual_cost;
    }
    
    //@ assert ((ret) >= 0 && (ret) <= (actual_cost));
    return ret;
}
