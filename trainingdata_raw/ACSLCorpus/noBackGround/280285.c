#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((a) < 10 && (b) < 10) ==> \result == (int32_t)(a * b);
    ensures ((a) >= 10 || (b) >= 10) ==> \result == -1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t min_ab;
    uint32_t max_ab;
    int32_t result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    
    min_ab = (a < b) ? a : b;
    max_ab = (a > b) ? a : b;

    if (min_ab < 10 && max_ab < 10)
    {
        //@ assert ((a) < 10 && (b) < 10);
        //@ assert a * b < 100;
        result = (int32_t)(a * b);
    }
    else
    {
        //@ assert ((a) >= 10 || (b) >= 10);
        result = -1;
    }
    
    return result;
}
