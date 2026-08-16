#include <limits.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + ((a)) * (1 + ((a)))));
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (a) <= 10);
    
    //@ assert 1 <= (1 + (a) * (1 + (a)));
    //@ assert (1 + (a) * (1 + (a))) <= 111;
    
    //@ assert 1 <= ((a) * (1 + ((a)) * (1 + ((a)))));
    //@ assert ((a) * (1 + ((a)) * (1 + ((a))))) <= 1110;

    result = a * (1 + a * (1 + a));
    
    //@ assert result == ((a) * (1 + ((a)) * (1 + ((a)))));
    return result;
}
