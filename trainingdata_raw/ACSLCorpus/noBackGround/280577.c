#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    
    if (a + b - 1 >= 1)
    {
        //@ assert a + b - 1 >= 1;
        //@ assert a * b >= a + b - 1;
        //@ assert a * b <= 100 * 100;
        //@ assert a * b - a >= 0;
        //@ assert a * b - a - b >= -1;
        //@ assert a * b - a - b + 1 > 0;
        
        result = a * b - a - b + 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
