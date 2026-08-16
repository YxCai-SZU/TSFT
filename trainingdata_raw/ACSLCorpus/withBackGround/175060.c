#include <stdbool.h>

/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k && k <= 100 &&
        1 <= x && x <= 100000;

    logic integer safe_mult(integer k) = k * 500;

    lemma mult_bound: \forall integer k; 1 <= k <= 100 ==> safe_mult(k) <= 50000;
*/

/*@
    requires is_valid_params(k, x);
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    bool ans = false;
    
    //@ assert 1 <= k && k <= 100;
    //@ assert k * 500 <= 50000;
    
    if (k * 500 >= x) {
        ans = true;
    }
    
    return ans;
}
