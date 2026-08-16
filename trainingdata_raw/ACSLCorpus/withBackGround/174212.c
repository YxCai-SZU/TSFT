#include <stdint.h>

/*@
    predicate no_overflow(int64_t sale, int64_t cost) =
        sale >= 0 && cost >= 0 &&
        sale <= INT64_MAX && cost <= INT64_MAX &&
        (long long)sale - (long long)cost <= (long long)INT64_MAX &&
        (long long)sale - (long long)cost >= (long long)INT64_MIN;
*/

/*@
    logic integer net_gain_result(integer sale, integer cost) = sale - cost;
*/

/*@
    lemma subtraction_bounds:
        \forall integer sale, cost;
            sale >= 0 && cost >= 0 &&
            sale <= INT64_MAX && cost <= INT64_MAX &&
            sale - cost <= INT64_MAX && sale - cost >= INT64_MIN ==>
            net_gain_result(sale, cost) == sale - cost;
*/

/*@
    requires no_overflow(actual_cost, sale_amount);
    ensures \result == net_gain_result(sale_amount, actual_cost);
    assigns \nothing;
*/
int64_t net_gain(int64_t actual_cost, int64_t sale_amount)
{
    //@ assert sale_amount >= 0 && actual_cost >= 0;
    //@ assert sale_amount <= INT64_MAX && actual_cost <= INT64_MAX;
    //@ assert (long long)sale_amount - (long long)actual_cost <= (long long)INT64_MAX;
    //@ assert (long long)sale_amount - (long long)actual_cost >= (long long)INT64_MIN;
    //@ assert sale_amount - actual_cost <= INT64_MAX;
    //@ assert sale_amount - actual_cost >= INT64_MIN;
    
    return sale_amount - actual_cost;
}
