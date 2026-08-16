#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 15;
*/

/*@
    requires is_in_range(x);
    ensures \result == ((x & 0) == 0);
    assigns \nothing;
*/
bool func(unsigned int x) {
    // Variable declarations at top
    bool result;
    
    //@ assert is_in_range(x);
    
    //@ assert (x & 0) == 0;
    
    result = ((x & 0) == 0);
    return result;
}
