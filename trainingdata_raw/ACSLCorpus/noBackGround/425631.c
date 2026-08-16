#include <stdint.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == -1 || \result == 0;
    ensures \result == -1 ==> ((a) < 10 && (b) < 10);
    ensures \result == 0 ==> !((a) < 10 && (b) < 10);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    if (a < 10 && b < 10) {
        result = -1;
    } else {
        //@ assert !((a) < 10 && (b) < 10);
        result = 0;
    }
    
    return result;
}
