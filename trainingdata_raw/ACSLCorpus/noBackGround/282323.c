#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - ((a) + (b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a >= 2 && a <= 100;
    //@ assert b >= 2 && b <= 100;
    //@ assert a + b >= 4;
    //@ assert a + b <= 200;
    //@ assert a * b >= 4;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;
    
    uint32_t result;
    result = a * b - (a + b - 1);
    return result;
}
