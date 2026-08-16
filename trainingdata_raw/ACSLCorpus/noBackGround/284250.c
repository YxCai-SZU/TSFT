#include <limits.h>

/*@
    requires ((l) >= 0) && ((l) * (l) * (l) <= INT_MAX);
    ensures \result == l * l * l;
    assigns \nothing;
*/
int volume_cube(int l)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert l >= 0 && l <= 1290;
    //@ assert l * l >= 0 && l * l <= 1664100;
    //@ assert l * l * l >= 0 && l * l * l <= INT_MAX;
    
    result = l * l * l;
    return result;
}
