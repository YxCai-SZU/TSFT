#include <stdint.h>

/*@
    requires actual_cost >= 0;
    requires sale_amount >= 0;
    ensures \result == (sale_amount > actual_cost ? sale_amount - actual_cost : 0);
    ensures \result >= 0;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    //@ assert ((actual_cost) >= 0);
    //@ assert ((sale_amount) >= 0);
    
    if (sale_amount > actual_cost)
    {
        //@ assert sale_amount - actual_cost >= 0;
        ret = sale_amount - actual_cost;
    }
    else
    {
        //@ assert 0 >= 0;
        ret = 0;
    }
    
    //@ assert ret >= 0;
    return ret;
}
