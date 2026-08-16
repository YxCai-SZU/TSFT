#include <limits.h>

/*@
    requires (-40 <= (x) <= 40);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int func(int x)
{
    int ret;
    
    //@ assert -40 <= x && x <= 40;
    
    //@ assert -40 * 40 <= x * x && x * x <= 40 * 40;
    
    //@ assert -40 * 40 * 40 <= x * x * x && x * x * x <= 40 * 40 * 40;
    
    ret = x * x * x;
    
    return ret;
}
