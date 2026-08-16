#include <stdbool.h>

/*@ predicate is_nonnegative(integer value) = value >= 0; */

/*@
    requires is_nonnegative(actual_cost);
    requires is_nonnegative(sale_amount);
    ensures \result <==> sale_amount > actual_cost;
    assigns \nothing;
*/
bool has_profit(long actual_cost, long sale_amount)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_nonnegative(actual_cost) && is_nonnegative(sale_amount);
    
    result = sale_amount > actual_cost;
    return result;
}

/*@
    lemma profit_lemma:
        \forall integer cost, sale;
        is_nonnegative(cost) && is_nonnegative(sale) && sale > cost ==>
        \exists bool r; r == true;
*/
