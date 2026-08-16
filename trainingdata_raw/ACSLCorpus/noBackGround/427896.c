#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top
    int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert ((a) * (b)) <= INT_MAX;
    
    result = a * b;
    
    //@ assert result == ((a) * (b));
    
    return result;
}
