#include <limits.h>

/*@
    requires (-1290 <= (x) <= 1290);
    ensures \result == x*x*x;
    assigns \nothing;
*/
int cube(int x)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert (-1290 <= (x) <= 1290);
    
    //@ assert (-1290*1290 <= (x)*(x) <= 1290*1290);
    
    //@ assert (-1290*1290*1290 <= (x)*(x)*(x) <= 1290*1290*1290);
    
    result = x * x * x;
    //@ assert result == x*x*x;
    
    return result;
}
