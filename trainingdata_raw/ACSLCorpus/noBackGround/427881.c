#include <stdint.h>

/*@ requires 1 <= x <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> x % 2 != 0 && x % 3 != 0 && x % 5 != 0;
    ensures \result == 0 ==> ((x) % 2 == 0 || (x) % 3 == 0 || (x) % 5 == 0);
    assigns \nothing;
 */
int32_t func(uint32_t x)
{
    int32_t result;
    
    if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0)
    {
        //@ assert x % 2 != 0 && x % 3 != 0 && x % 5 != 0;
        result = 1;
    }
    else
    {
        //@ assert ((x) % 2 == 0 || (x) % 3 == 0 || (x) % 5 == 0);
        result = 0;
    }
    
    return result;
}
