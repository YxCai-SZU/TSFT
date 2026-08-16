#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) == ((a) <= (b)));
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    //@ assert (a <= b) == (a <= b);
    
    result = a <= b;
    
    //@ assert ((result) == ((a) <= (b)));
    return result;
}
