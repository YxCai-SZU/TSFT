#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer k) =
        1 <= n && n <= 100 &&
        1 <= k && k <= 100;

    logic integer condition(integer n, integer k) = k * 2 - 1;

    lemma condition_lemma:
        \forall integer n, k;
        is_valid_params(n, k) ==> 
        (condition(n, k) >= n ==> condition(n, k) >= n) &&
        (condition(n, k) < n ==> condition(n, k) < n);
*/

/*@
    requires is_valid_params(n, k);
    ensures \result == (k * 2 - 1 >= n);
    assigns \nothing;
*/
bool func(int n, int k)
{
    // Variable declarations at scope top
    bool result;
    int condition_value;
    
    condition_value = k * 2 - 1;
    
    if (condition_value >= n)
    {
        //@ assert condition_value >= n;
        result = true;
    }
    else
    {
        //@ assert condition_value < n;
        result = false;
    }
    
    return result;
}
