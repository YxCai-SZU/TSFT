#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 9 &&
        1 <= (B) && (B) <= 9 &&
        1 <= (C) && (C) <= 9);
    ensures ((\result) == 10 || (\result) == 20 || (\result) == 30 || (\result) == -1);
    ensures \result == -1 ==> A + B + C >= 30;
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C)
{
    uint32_t sum;
    int32_t result;

    sum = A + B + C;

    if (sum < 10) {
        //@ assert sum < 10;
        result = 10;
    } else if (sum < 20) {
        //@ assert sum < 20;
        result = 20;
    } else if (sum < 30) {
        //@ assert sum < 30;
        result = 30;
    } else {
        //@ assert sum >= 30;
        result = -1;
    }

    //@ assert ((result) == 10 || (result) == 20 || (result) == 30 || (result) == -1);
    return result;
}
