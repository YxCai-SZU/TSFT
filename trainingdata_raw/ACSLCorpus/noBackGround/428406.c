#include <stdbool.h>

/*@
    requires ((1 <= ((A)) <= 100) && (1 <= ((B)) <= 100) && (1 <= ((C)) <= 100));
    ensures \result == (C - (B - A) > 0);
    assigns \nothing;
*/
bool func(long A, long B, long C)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (A) <= 100);
    //@ assert (1 <= (B) <= 100);
    //@ assert (1 <= (C) <= 100);
    
    result = C - (B - A) > 0;
    
    return result;
}
