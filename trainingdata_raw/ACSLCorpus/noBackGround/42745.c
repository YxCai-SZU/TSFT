#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (((a) * (b)) - ((a) + (b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert a + b - 1 <= 100 + 100 - 1;
    //@ assert (a * b) >= 4;
    //@ assert (a * b) <= 10000;
    //@ assert (a * b) - (a + b - 1) >= 4 - 201;
    
    result = (a * b) - (a + b - 1);
    
    //@ assert result == (((a) * (b)) - ((a) + (b) - 1));
    return result;
}
