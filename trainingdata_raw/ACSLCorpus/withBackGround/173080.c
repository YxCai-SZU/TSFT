#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    predicate result_correct(integer r, integer res) = res == 3 * r * r;
*/

/*@
    requires r_in_range(r);
    ensures result_correct(r, \result);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 300 * 100;
    
    result = 3 * r * r;
    
    //@ assert result_correct(r, result);
    return result;
}
