#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer calculate_result(integer r, integer pi) = r * 2 * pi;
*/

/*@
    requires r_in_range(r);
    ensures \result == calculate_result(r, 3);
    assigns \nothing;
*/
int func(int r)
{
    int pi;
    int result;
    
    pi = 3;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 2 * pi <= 200;
    
    result = r * 2 * pi;
    
    return result;
}
