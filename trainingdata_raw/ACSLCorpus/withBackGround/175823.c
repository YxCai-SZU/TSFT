#include <stdint.h>

/*@ predicate non_negative(integer value) = value >= 0; */

/*@
    requires non_negative(actual_cost);
    requires non_negative(sale_amount);
    ensures \result == sale_amount - actual_cost;
    assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    int64_t ret;
    
    //@ assert non_negative(actual_cost);
    //@ assert non_negative(sale_amount);
    
    ret = sale_amount - actual_cost;
    
    //@ assert ret == sale_amount - actual_cost;
    return ret;
}

int main()
{
    return 0;
}
