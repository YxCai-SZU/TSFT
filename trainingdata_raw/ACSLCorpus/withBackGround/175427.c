#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r) {
    int result;
    
    //@ assert 1 <= r <= 100;
    result = 3 * r;
    
    //@ assert result == 3 * r;
    //@ assert 1 <= result <= 300;
    //@ assert result * r <= 300 * 100;
    
    result *= r;
    
    //@ assert result == 3 * r * r;
    return result;
}
