#include <stdint.h>

/*@
    requires (-46340 <= (x) && (x) <= 46340);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert (-46340 <= (x) && (x) <= 46340);
    //@ assert -46340*46340 <= ((x) * (x)) && ((x) * (x)) <= 46340*46340;
    //@ assert ((x) * (x)) == ((x) * (x));
    
    result = x * x;
    return result;
}
