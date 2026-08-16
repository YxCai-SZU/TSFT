#include <stdint.h>

/*@
    requires (-1290 <= (n) && (n) <= 1290);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    //@ assert (-1290 <= (n) && (n) <= 1290);
    
    int64_t result;
    result = n * n * n;
    
    //@ assert result == ((n) * (n) * (n));
    return result;
}
