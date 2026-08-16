#include <stdint.h>

/*@
  requires ((actual_cost) >= 0);
  requires ((sale_amount) >= 0);
  ensures \result >= -actual_cost;
  ensures \result <= sale_amount - actual_cost;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    //@ assert ((sale_amount) >= 0);
    //@ assert ((actual_cost) >= 0);
    return sale_amount - actual_cost;
}
