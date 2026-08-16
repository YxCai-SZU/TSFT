#include <stdint.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    requires a != b;
    ensures \result == 6 - a - b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    
    if ((a == 1 && b == 2) || (a == 2 && b == 1))
    {
        //@ assert (6 - (a) - (b)) == 3;
        result = 3;
    }
    else if ((a == 1 && b == 3) || (a == 3 && b == 1))
    {
        //@ assert (6 - (a) - (b)) == 2;
        result = 2;
    }
    else
    {
        //@ assert (6 - (a) - (b)) == 1;
        result = 1;
    }

    return result;
}
