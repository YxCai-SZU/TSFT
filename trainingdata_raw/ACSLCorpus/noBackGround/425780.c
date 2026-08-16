#include <stdint.h>

/*@
    requires 1 <= a <= 20 && 1 <= b <= 20;
    ensures
        (a <= 9 && b <= 9 ==> \result == (int32_t)(a * b)) &&
        ((a > 9 || b > 9) ==> \result == -1);
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;
    
    if (a <= 9 && b <= 9) {
        //@ assert ((1 <= ((a)) <= 9) && (1 <= ((b)) <= 9));
        result = (int32_t)(a * b);
    } else {
        //@ assert (!((1 <= (((a))) <= 9) && (1 <= (((b))) <= 9)) && (1 <= ((a)) <= 20) && (1 <= ((b)) <= 20));
        result = -1;
    }
    
    return result;
}
