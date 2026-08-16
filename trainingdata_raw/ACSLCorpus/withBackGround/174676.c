#include <stdbool.h>
#include <limits.h>

/*@ predicate profit_condition(integer actual_cost, integer sale_amount) =
      sale_amount > actual_cost;
*/

/*@
  requires actual_cost >= LLONG_MIN && actual_cost <= LLONG_MAX;
  requires sale_amount >= LLONG_MIN && sale_amount <= LLONG_MAX;
  ensures \result == (sale_amount > actual_cost);
*/
bool has_profit(long long actual_cost, long long sale_amount)
{
    // Variable declarations at scope top
    bool result;

    //@ assert sale_amount >= LLONG_MIN && sale_amount <= LLONG_MAX;
    //@ assert actual_cost >= LLONG_MIN && actual_cost <= LLONG_MAX;
    //@ assert sale_amount > actual_cost ==> sale_amount - actual_cost >= 0;

    result = sale_amount > actual_cost;
    return result;
}
