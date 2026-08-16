#include <stdint.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a < 10 && b < 10) ==> \result == (int)(a * b);
    ensures !(a < 10 && b < 10) ==> \result == -1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    if (a < 10 && b < 10)
    {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    }
    else
    {
        result = -1;
    }
    
    return result;
}
