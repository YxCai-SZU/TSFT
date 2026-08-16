#include <stdbool.h>

/*@
    predicate X_in_range(integer X) = -40 <= X <= 40;
    predicate X_ge_30(integer X) = X >= 30;
*/

/*@
    requires X_in_range(X);
    ensures \result == (X >= 30);
    assigns \nothing;
*/
bool func(int X) {
    // Variable declarations at scope top
    int i;
    
    if (X >= 30) {
        //@ assert X >= 30;
        return true;
    } else {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10;
            loop invariant X_in_range(X);
            loop invariant X < 30;
            loop assigns i;
            loop variant 10 - i;
        */
        while (i < 10) {
            //@ assert i < 10;
            i = i + 1;
        }
        //@ assert X < 30;
        return false;
    }
}
