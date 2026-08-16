#include <limits.h>

/*@
    requires (0 < (l) <= INT_MAX / 2 &&
        0 < (b) <= INT_MAX / 2 &&
        (l) + (b) <= INT_MAX / 2);
    ensures \result == (2 * ((l) + (b)));
    assigns \nothing;
*/
int rectangle_perimeter(int l, int b) {
    //@ assert 0 < l <= INT_MAX / 2;
    //@ assert 0 < b <= INT_MAX / 2;
    //@ assert l + b <= INT_MAX / 2;
    //@ assert 2 * (l + b) <= INT_MAX;
    
    return 2 * (l + b);
}
