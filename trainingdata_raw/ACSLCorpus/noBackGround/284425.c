#include <limits.h>

/*@
    requires ((l) > 0 && (l) * (l) <= INT_MAX);
    ensures \result == ((l) * (l));
    ensures \result > 0;
    assigns \nothing;
*/
int find_diagonal_square(int l) {
    // Variable declarations at top of scope
    int result;

    //@ assert l > 0;
    //@ assert l * l <= INT_MAX;
    //@ assert l * l > 0;

    result = l * l;
    
    //@ assert result == l * l;
    //@ assert result > 0;
    
    return result;
}
