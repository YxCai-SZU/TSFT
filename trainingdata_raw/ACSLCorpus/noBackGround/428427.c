#include <stdbool.h>

/*@
    requires \true;
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    
    //@ assert x >= 30 ==> x >= 30;
    
    result = (x >= 30);
    return result;
}
