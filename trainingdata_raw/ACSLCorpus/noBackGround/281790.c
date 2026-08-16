#include <stdbool.h>

/*@
    requires (1 <= (a) <= 5000) && (1 <= (b) <= 5000) && (1 <= (c) <= 5000);
    ensures \result == (((a) + (b)) >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (a) <= 5000);
    //@ assert (1 <= (b) <= 5000);
    //@ assert (1 <= (c) <= 5000);
    
    result = (a + b) >= c;
    
    //@ assert result == (((a) + (b)) >= c);
    
    return result;
}
