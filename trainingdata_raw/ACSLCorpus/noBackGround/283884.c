#include <stdbool.h>

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert x == 0 || x == 1;
    
    result = 1 - x;
    
    return result;
}
