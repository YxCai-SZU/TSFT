#include <stdint.h>

/*@
    requires (1 <= (A) <= 20 && 1 <= (B) <= 20);
    ensures (A < 10 && B < 10 ==> \result == A * B);
    ensures (A >= 10 || B >= 10 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t B)
{
    uint32_t max_value;
    int32_t result;

    //@ assert (1 <= (A) <= 20 && 1 <= (B) <= 20);
    max_value = (A > B) ? A : B;

    if (max_value < 10)
    {
        //@ assert A < 10 && B < 10;
        //@ assert A * B <= 400;
        result = (int32_t)(A * B);
    }
    else
    {
        result = -1;
    }

    return result;
}
