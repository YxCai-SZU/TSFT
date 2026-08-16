#include <stdbool.h>

/*@
    predicate is_valid_k(integer k) =
        1 <= k <= 9;
*/

/*@
    requires is_valid_k(k);
    ensures \result == (k == 3 || k == 5 || k == 7);
    assigns \nothing;
*/
bool func(long k)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_valid_k(k);
    
    result = (k == 3 || k == 5 || k == 7);
    
    //@ assert result == (k == 3 || k == 5 || k == 7);
    return result;
}
