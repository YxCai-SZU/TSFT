#include <stdint.h>

/*@
    requires (-1290 <= (x) && (x) <= 1290);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    //@ assert (-1290 <= (x) && (x) <= 1290);
    
    int64_t result;
    result = x * x * x;
    
    //@ assert result == ((x) * (x) * (x));
    return result;
}
