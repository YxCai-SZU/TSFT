#include <stdint.h>

/*@
    requires (3 <= (a) <= 100);
    ensures \result == ((((a)) * ((a)) * ((a))) / 2);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    uint32_t a_square;
    uint32_t a_cubed;
    int32_t half_a_cubed;

    //@ assert 3 <= a <= 100;
    //@ assert a * a <= 10000;
    //@ assert a * a * a <= 1000000;
    
    a_square = a * a;
    //@ assert a_square * a <= 1000000;
    
    a_cubed = a * a_square;
    half_a_cubed = (int32_t)(a_cubed / 2);
    
    return half_a_cubed;
}
