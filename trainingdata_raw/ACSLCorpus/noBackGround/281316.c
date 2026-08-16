#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000);
    requires ((a) * (a) * (a) <= 1000000000);
    ensures \result == a * a * a;
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations
    int32_t result;
    
    // Precondition verification
    //@ assert 1 <= a && a <= 10000;
    
    //@ assert 1 <= a * a && a * a <= 10000 * 10000;
    
    //@ assert 1 <= a * a * a && a * a * a <= 10000 * 10000 * 10000;
    
    // Actual calculation
    result = a * a * a;
    
    // Postcondition verification
    //@ assert result == a * a * a;
    
    return result;
}
