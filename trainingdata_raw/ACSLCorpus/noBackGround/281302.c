#include <stdint.h>

/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    assigns \nothing;
    ensures ((a) <= 9 && (b) <= 9) ==> \result == ((a) * (b));
    ensures !((a) <= 9 && (b) <= 9) ==> \result == -1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t max_value;
    int32_t result;

    max_value = (a > b) ? a : b;

    if (max_value <= 9)
    {
        //@ assert ((a) <= 9 && (b) <= 9);
        //@ assert ((a) * (b)) <= 81;
        result = (int32_t)(a * b);
    }
    else
    {
        //@ assert !((a) <= 9 && (b) <= 9);
        result = -1;
    }

    return result;
}
