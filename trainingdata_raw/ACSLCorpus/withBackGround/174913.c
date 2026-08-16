#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    logic integer calculate(integer r, integer pi) = 2 * r * pi;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate(r, 3);
    assigns \nothing;
*/
int func(int r) {
    int pi;
    int res;
    
    pi = 3;
    
    //@ assert 2 * r * pi <= 200 * 3;
    
    res = 2 * r * pi;
    return res;
}
