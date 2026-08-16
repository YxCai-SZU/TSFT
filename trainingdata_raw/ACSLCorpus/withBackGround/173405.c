#include <limits.h>

/*@
    predicate valid_range(integer n) = n > 0 && n < 10;
    logic integer cube(integer n) = n * n * n;
*/

/*@
    requires valid_range(n);
    ensures \result == cube(n);
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert n > 0 && n < 10;
    
    //@ assert n * n < 100;
    
    //@ assert n * n * n < 1000;
    
    res = n * n * n;
    
    //@ assert res == cube(n);
    
    return res;
}
