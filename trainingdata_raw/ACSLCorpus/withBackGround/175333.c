#include <stdbool.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_bounds: \forall integer r; is_valid_range(r) ==> square(r) <= 10000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
int func(int r)
{
    int ans;
    
    //@ assert is_valid_range(r);
    //@ assert square(r) >= 1 * 1 && square(r) <= 100 * 100;
    //@ assert square(r) <= 10000;
    
    ans = r * r;
    
    return ans;
}
