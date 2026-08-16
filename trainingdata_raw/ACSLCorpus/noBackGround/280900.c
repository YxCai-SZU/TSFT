#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) < 100) && (0 <= (b) && (b) < 100);
    ensures \result == (a < b);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (0 <= (a) && (a) < 100);
    //@ assert (0 <= (b) && (b) < 100);
    
    result = a < b;
    return result;
}
