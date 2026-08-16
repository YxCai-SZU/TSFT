#include <limits.h>

/*@
    requires ((l) >= 0) && ((b) >= 0);
    requires ((l) * (l) + (b) * (b) <= INT_MAX);
    ensures \result == ((l) * (l) + (b) * (b));
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b) {
    //@ assert ((l) >= 0);
    //@ assert ((b) >= 0);
    //@ assert ((l) * (l) + (b) * (b) <= INT_MAX);
    //@ assert ((l) * (l) + (b) * (b)) >= 0;
    //@ assert l * l <= INT_MAX;
    //@ assert b * b <= INT_MAX;
    
    return l * l + b * b;
}
