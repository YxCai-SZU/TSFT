#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Declare all variables at the top
    int64_t a_squared;
    int64_t a_cubed;
    int64_t result;
    
    //@ assert (1 <= (a) <= 10);
    
    // Calculate a * a
    a_squared = a * a;
    //@ assert a_squared == ((a) * (a));
    
    // Calculate a * a * a
    a_cubed = a * a * a;
    //@ assert a_cubed == ((a) * (a) * (a));
    
    // Calculate final result
    result = a + a_squared + a_cubed;
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    
    return result;
}
