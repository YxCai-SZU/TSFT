#include <stdint.h>

/*@
    requires sale_amount >= 0;
    requires sale_amount <= 2 * 9223372036854775807;
    requires actual_cost >= 0;
    requires actual_cost <= 2 * 9223372036854775807;
    ensures \result >= 0;
    ensures \result <= 2 * 9223372036854775807;
    ensures \result == (actual_cost > sale_amount ? actual_cost - sale_amount : 0);
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t loss;
    //@ assert sale_amount >= 0;
    //@ assert sale_amount <= 2 * 9223372036854775807;
    //@ assert actual_cost >= 0;
    //@ assert actual_cost <= 2 * 9223372036854775807;
    
    if (actual_cost > sale_amount)
    {
        loss = actual_cost - sale_amount;
    }
    else
    {
        loss = 0;
    }
    
    //@ assert loss >= 0;
    //@ assert loss <= 2 * 9223372036854775807;
    //@ assert loss == (actual_cost > sale_amount ? actual_cost - sale_amount : 0);
    
    return loss;
}

int main()
{
    return 0;
}
