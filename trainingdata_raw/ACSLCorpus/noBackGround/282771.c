#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
*/
int32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t a_square_val;
    uint32_t a_cubed_val;
    uint32_t result;
    
    //@ assert a <= 10;
    //@ assert a >= 1;
    
    //@ assert ((a) * (a)) <= 100;
    a_square_val = a * a;
    
    //@ assert ((a) * (a) * (a)) <= 1000;
    a_cubed_val = a * a * a;
    
    result = a + a_square_val + a_cubed_val;
    
    //@ assert result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return (int32_t)result;
}
