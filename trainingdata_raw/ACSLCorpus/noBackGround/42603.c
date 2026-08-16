#include <stdint.h>

/*@
    requires 1 <= a <= 20 && 1 <= b <= 20;
    ensures
        (a < 10 && b < 10 ==> \result == (int32_t)(a * b)) &&
        (!(a < 10 && b < 10) ==> \result == -1);
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_is_lt_10;
    uint32_t b_is_lt_10;
    int32_t result;
    
    a_is_lt_10 = a < 10;
    b_is_lt_10 = b < 10;
    
    if (a_is_lt_10 && b_is_lt_10) {
        //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20 && (a) < 10 && (b) < 10);
        //@ assert 1 <= a * b <= 100;
        result = (int32_t)(a * b);
    } else {
        //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20 && !((a) < 10 && (b) < 10));
        result = -1;
    }
    
    return result;
}
