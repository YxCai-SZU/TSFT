#include <stdint.h>

/*@
    requires (-1290 <= (x) && (x) <= 1290);
    ensures \result == x * x * x;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    //@ assert (-1290 <= (x) && (x) <= 1290);
    
    int64_t x_sq;
    int64_t result;
    
    x_sq = x * x;
    //@ assert -1290*1290 <= x_sq <= 1290*1290;
    
    result = x_sq * x;
    //@ assert -1290*1290*1290 <= result <= 1290*1290*1290;
    
    //@ assert -9223372036854775808 <= result <= 9223372036854775807;
    
    return result;
}
