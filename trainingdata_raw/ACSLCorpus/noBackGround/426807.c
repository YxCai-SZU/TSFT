#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_pow_2;
    int64_t a_pow_3;
    int64_t result;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    // Calculate a^2
    a_pow_2 = a * a;
    //@ assert a_pow_2 == ((a) * (a));
    
    // Calculate a^3
    a_pow_3 = a * a * a;
    //@ assert a_pow_3 == ((a) * (a) * (a));
    
    // Calculate final result
    result = a + a_pow_2 + a_pow_3;
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    
    return result;
}
