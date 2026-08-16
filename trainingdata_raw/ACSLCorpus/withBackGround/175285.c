#include <stdbool.h>

/*@
    predicate valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer scaled_k(integer k) = 500 * k;

    lemma scaled_k_bound: \forall integer k; 1 <= k <= 100 ==> scaled_k(k) <= 100000;
*/

/*@
    requires valid_params(k, x);
    ensures \result == (scaled_k(k) >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int scaled;
    bool result;

    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    //@ assert scaled_k(k) <= 100000;
    
    scaled = 500 * k;
    //@ assert scaled == scaled_k(k);
    
    result = scaled >= x;
    //@ assert result == (scaled_k(k) >= x);
    
    return result;
}
