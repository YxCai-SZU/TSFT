#include <stdint.h>

/*@
    requires ((actual_cost) >= 0) && ((sale_amount) >= 0);
    ensures \result >= 0 && \result <= actual_cost;
    ensures \result == actual_cost - sale_amount || \result == 0;
*/
int64_t loss_amount(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    //@ assert ((actual_cost) >= 0) && ((sale_amount) >= 0);
    
    if (actual_cost > sale_amount)
    {
        //@ assert actual_cost - sale_amount >= 0;
        //@ assert actual_cost - sale_amount <= actual_cost;
        ret = actual_cost - sale_amount;
    }
    else
    {
        //@ assert 0 >= 0;
        //@ assert 0 <= actual_cost;
        ret = 0;
    }
    
    //@ assert ret >= 0 && ret <= actual_cost;
    //@ assert ret == actual_cost - sale_amount || ret == 0;
    return ret;
}
