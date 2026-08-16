#include <stdbool.h>

/*@
    requires ((x & 1) == 0 || (x & 1) == 1);
    ensures ((\result == 1) && ((x & 1) == 1)) || ((\result == 0) && ((x & 1) == 0));
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert ((x & 1) == 0 || (x & 1) == 1);
    
    result = x & 1;
    
    return result;
}
