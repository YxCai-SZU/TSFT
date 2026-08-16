#include <stdbool.h>

/*@
    requires actual_cost >= 0;
    requires sale_amount >= 0;
    ensures \result == (sale_amount > actual_cost);
    assigns \nothing;
*/
bool has_profit(long actual_cost, long sale_amount)
{
    //@ assert sale_amount >= 0 && actual_cost >= 0;
    return sale_amount > actual_cost;
}
