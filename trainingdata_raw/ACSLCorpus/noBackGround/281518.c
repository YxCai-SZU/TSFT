#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures ((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == ((a) * (b));
    ensures !((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_is_greater_than_9;
    uint32_t b_is_greater_than_9;
    int32_t result;

    a_is_greater_than_9 = (a > 9) ? 1 : 0;
    b_is_greater_than_9 = (b > 9) ? 1 : 0;

    //@ assert a <= 20 && b <= 20;
    //@ assert ((a) * (b)) <= 400;

    if (a_is_greater_than_9 + b_is_greater_than_9 > 0)
    {
        result = -1;
    }
    else
    {
        result = (int32_t)(a * b);
    }

    return result;
}
