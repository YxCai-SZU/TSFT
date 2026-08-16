#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 0;
    ensures \result <= ((a) * (b)) / 2;
    ensures \result == ((a) * (b)) / 2 || \result == (((a) * (b)) + 1) / 2 - c;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert ((a) * (b)) <= 10000;
    
    result = (a * b) / 2;
    
    if (result > c)
    {
        result = (a * b + 1) / 2 - c;
        //@ assert result == (((a) * (b)) + 1) / 2 - c;
    }
    else
    {
        //@ assert result >= 0;
        //@ assert result <= ((a) * (b)) / 2;
        //@ assert result == ((a) * (b)) / 2;
    }
    
    return result;
}
