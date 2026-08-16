#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    ensures (a < 10 && b < 10 ==> \result == a * b) &&
            (a < 10 && b >= 10 ==> \result == -1) &&
            (a >= 10 && b < 10 ==> \result == -1) &&
            (a >= 10 && b >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_value;
    int32_t result;

    //@ assert (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    
    if (a > b) {
        max_value = a;
    } else {
        max_value = b;
    }

    if (max_value < 10) {
        //@ assert a < 10 && b < 10;
        //@ assert a * b < 10000;
        result = (int32_t)(a * b);
    } else {
        result = -1;
    }

    return result;
}
