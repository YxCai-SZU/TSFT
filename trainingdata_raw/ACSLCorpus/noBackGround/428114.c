#include <stdint.h>

/*@
  requires ((actual_cost) >= 0);
  requires ((sale_amount) >= 0);
  ensures \result == sale_amount - actual_cost;
  ensures \result >= -actual_cost;
  ensures \result <= sale_amount;
  assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    // Variable declarations at the top
    int64_t ret;

    //@ assert ((sale_amount) >= 0);
    //@ assert ((actual_cost) >= 0);

    ret = sale_amount - actual_cost;
    return ret;
}
