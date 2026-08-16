#include <stdbool.h>

/*@
    predicate in_range(integer x) = 30 <= x && x <= 40;
*/

/*@
    requires -40 <= x <= 40;
    ensures (x >= 30 && x <= 40) ==> \result == true;
    ensures (x < 30 || x > 40) ==> \result == false;
    assigns \nothing;
*/
bool func(int x) {
    int i;
    
    if (x >= 30 && x <= 40) {
        return true;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 1000000;
            loop assigns i;
        */
        while (i < 1000000) {
            i++;
        }
        return false;
    }
}
