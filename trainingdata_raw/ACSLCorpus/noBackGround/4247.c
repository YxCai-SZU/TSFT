#include <stdint.h>

/*@ requires (1 <= (a) && (a) <= 100);
    ensures \result == a * a;
    assigns \nothing;
 */
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert 1 <= a;
    //@ assert a <= 100;
    //@ assert a * a >= 0;
    //@ assert a * a <= 10000;
    
    result = a * a;
    return result;
}
