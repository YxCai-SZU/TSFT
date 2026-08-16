#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result == (((a) * (b)) <= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    result = (a * b <= c);
    
    //@ assert result == (((a) * (b)) <= c);
    return result;
}
