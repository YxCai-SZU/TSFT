#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((((a) - (c))) * (((b) - (d))));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    //@ assert -99 <= a - c <= 99;
    //@ assert -99 <= b - d <= 99;
    //@ assert -9801 <= (a - c) * (b - d) <= 9801;
    
    result = (a - c) * (b - d);
    
    //@ assert result == ((((a) - (c))) * (((b) - (d))));
    
    return result;
}
