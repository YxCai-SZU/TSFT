#include <stdbool.h>

/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer product(integer k, integer en) = k * en;

    lemma product_bounds: \forall integer k, integer en;
        is_valid_params(k, 100000) && en == 500 ==> 0 <= product(k, en) <= 50000;
*/

/*@
    requires is_valid_params(k, x);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(int k, int x)
{
    int en = 500;
    int result;
    
    //@ assert 0 <= k * en <= 50000;
    //@ assert 500 * k <= 50000;
    
    result = (500 * k >= x);
    return result;
}
