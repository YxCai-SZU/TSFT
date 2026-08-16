#include <stdbool.h>

/*@
    predicate is_in_range(integer k) = 1 <= k && k <= 7;
*/

/*@
    requires is_in_range(k);
    ensures \result == 48 - k;
    assigns \nothing;
*/
int func(int k)
{
    int result;
    
    //@ assert is_in_range(k);
    //@ assert 48 - k == 48 - (integer)k;
    
    result = 48 - k;
    
    //@ assert result == 48 - k;
    return result;
}
