#include <stdbool.h>

/*@ predicate is_i64_range(integer x) =
      -0x8000000000000000 <= x && x <= 0x7FFFFFFFFFFFFFFF;
*/

/*@
  requires is_i64_range(actual_cost);
  requires is_i64_range(sale_amount);
  ensures \result == (sale_amount > actual_cost);
*/
bool has_profit(long long actual_cost, long long sale_amount)
{
    //@ assert is_i64_range(sale_amount);
    //@ assert is_i64_range(actual_cost);
    return sale_amount > actual_cost;
}
