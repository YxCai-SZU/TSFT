#include <stdbool.h>

/*@ predicate valid_range(integer R) = 1 <= R <= 100; */

/*@
    requires valid_range(R);
    ensures \result == 6 * R;
    assigns \nothing;
*/
int func(int R)
{
    // Variable declarations at top of scope
    int PI;
    int res;
    
    PI = 3;
    
    //@ assert PI == 3;
    
    res = R * 2 * PI;
    
    //@ assert res == 6 * R;
    
    return res;
}
