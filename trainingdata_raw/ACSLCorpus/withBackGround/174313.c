#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 100000;
    
    logic integer total_cost(integer k) = 500 * k;
    
    lemma cost_bound: \forall integer k; k_in_range(k) ==> total_cost(k) <= 50000;
*/

/*@
    requires k_in_range(k);
    requires x_in_range(x);
    ensures \result == (500 * k >= x);
*/
bool func(unsigned int k, unsigned int x)
{
    // Variable declarations at scope top
    bool result;
    unsigned int cost;
    
    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    cost = 500 * k;
    
    //@ assert cost <= 50000;
    
    result = (cost >= x);
    
    //@ assert result == (500 * k >= x);
    
    return result;
}
