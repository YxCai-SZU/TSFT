#include <stdbool.h>

/*@
    requires (0 <= (a) <= 32) && (0 <= (b) <= 32);
    ensures \result == (((a) * (a)) <= ((b) * 32));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 0 <= a * a <= 1024;
    //@ assert 0 <= b * 32 <= 1024;
    
    result = (a * a) <= (b * 32);
    
    //@ assert result == (((a) * (a)) <= ((b) * 32));
    return result;
}
