#include <stdbool.h>

/*@ predicate is_valid_input(integer x) = 1 <= x <= 100; */

/*@
    requires is_valid_input(x);
    ensures \result == 1;
    assigns \nothing;
*/
int func(int x) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= x <= 100;
    
    result = 1;
    return result;
}
