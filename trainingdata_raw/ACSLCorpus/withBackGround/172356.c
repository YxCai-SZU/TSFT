/*@
    predicate lower_bounds(integer n, integer k) =
        n >= 1 && k >= 1;
    
    predicate upper_bounds(integer n, integer k) =
        n <= 100 && k <= 100;
    
    predicate safe_addition(integer n) =
        n + 1 <= 101;
    
    logic integer half_n(integer n) = n / 2;
    logic integer half_n_plus_one(integer n) = (n + 1) / 2;
    
    predicate postcondition(integer n, integer k, integer result) =
        result == (half_n(n) >= k - 1 || half_n_plus_one(n) >= k);
    
    lemma bounds_lemma:
        \forall integer n, k;
            lower_bounds(n, k) && upper_bounds(n, k) ==> safe_addition(n);
*/

#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (n / 2 >= k - 1 || (n + 1) / 2 >= k);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert n >= 1 && k >= 1;
    //@ assert n <= 100 && k <= 100;
    //@ assert n + 1 <= 101;
    
    if (n / 2 >= k - 1 || (n + 1) / 2 >= k)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (n / 2 >= k - 1 || (n + 1) / 2 >= k);
    return result;
}
