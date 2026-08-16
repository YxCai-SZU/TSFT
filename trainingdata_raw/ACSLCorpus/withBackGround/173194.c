#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b) =
        1 <= a <= 100 && 0 <= b <= a;
*/

/*@
    requires is_valid_params(a, b);
    ensures \result == (b >= a);
    assigns \nothing;
*/
bool func(int a, int b) {
    // Variable declarations at top of scope
    int i = 0;
    
    if (b >= a) {
        return true;
    } else {
        //@ assert b < a;
        
        /*@
            loop invariant 0 <= i <= a;
            loop invariant 1 <= a <= 100;
            loop invariant 0 <= b <= a;
            loop invariant b < a;
            loop assigns i;
            loop variant a - i;
        */
        while (i < a) {
            if (a - i <= b) {
                return false;
            }
            i += 1;
        }
    }
    return false;
}
