#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert a >= 1 && a <= 10;
    
    //@ assert a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    //@ assert a + a * a <= 110;
    //@ assert a + a * a + a * a * a <= 1110;

    uint32_t ans = a + a * a + a * a * a;
    
    //@ assert ans == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    return ans;
}
