#include <stdint.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    int32_t result;

    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    
    sum = a + b;

    //@ assert \exists integer x, y; (1 <= (x) <= 3 && 1 <= (y) <= 3 && (x) != (y)) && x == a && y == b;
    
    result = 6 - (int32_t)a - (int32_t)b;
    
    //@ assert result == (6 - (a) - (b));
    
    return result;
}
