#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result == (a * b <= 1000);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a <= 100 && b <= 100;
    
    //@ assert a * b <= 10000;
    
    result = (a * b) <= 1000;
    
    return result;
}
