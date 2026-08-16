#include <stdint.h>

/*@
    requires ((actual_cost) >= 0);
    requires ((sale_amount) >= 0);
    ensures ((\result) >= 0);
    ensures \result <= sale_amount;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t gain;
    gain = sale_amount - actual_cost;
    if (gain > 0)
    {
        //@ assert gain >= 0;
        //@ assert gain <= sale_amount;
        return gain;
    }
    else
    {
        //@ assert 0 >= 0;
        //@ assert 0 <= sale_amount;
        return 0;
    }
}
