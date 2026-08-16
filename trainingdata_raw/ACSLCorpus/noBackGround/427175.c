#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result == 0 || \result == 1 || \result == -1;
    ensures \result == 0 ==> a == b;
    ensures \result == 1 ==> a > b;
    ensures \result == -1 ==> a < b;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    if (a == b)
    {
        result = 0;
        //@ assert result == 0 && a == b;
    }
    else if (a > b)
    {
        result = 1;
        //@ assert result == 1 && a > b;
    }
    else
    {
        //@ assert a < b;
        result = -1;
        //@ assert result == -1 && a < b;
    }
    
    return result;
}
