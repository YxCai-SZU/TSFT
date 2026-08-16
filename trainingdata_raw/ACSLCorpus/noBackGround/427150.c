#include <stdbool.h>

/*@
    requires (1 <= (x) <= 179);
    ensures ((\result) >= 1 && (\result) <= 360 && (\result) == 360 - (x));
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 360 >= 1;
    //@ assert 360 - x >= 1;
    
    result = 360 - x;
    
    return result;
}
