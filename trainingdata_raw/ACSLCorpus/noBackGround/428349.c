#include <limits.h>

/*@
    requires ((l) >= 0 && (b) >= 0) && ((l) * (l) <= INT_MAX && 
        (b) * (b) <= INT_MAX && 
        (l) * (l) + (b) * (b) <= INT_MAX);
    ensures \result == ((l) * (l) + (b) * (b));
    assigns \nothing;
*/
int rectangle_diagonal_squared(int l, int b) {
    //@ assert ((l) >= 0 && (b) >= 0);
    //@ assert ((l) * (l) <= INT_MAX &&          (b) * (b) <= INT_MAX &&          (l) * (l) + (b) * (b) <= INT_MAX);
    
    int lsquared = l * l;
    int bsquared = b * b;
    
    //@ assert lsquared == l * l;
    //@ assert bsquared == b * b;
    //@ assert lsquared + bsquared == ((l) * (l) + (b) * (b));
    
    return lsquared + bsquared;
}
