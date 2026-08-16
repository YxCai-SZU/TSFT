#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures \result == (((a) <= 9 && (b) <= 9) ? (a) * (b) : -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result;

    if (a > 9)
    {
        result = -1;
        //@ assert result == (((a) <= 9 && (b) <= 9) ? (a) * (b) : -1);
        return result;
    }
    else if (b > 9)
    {
        result = -1;
        //@ assert result == (((a) <= 9 && (b) <= 9) ? (a) * (b) : -1);
        return result;
    }
    else
    {
        //@ assert a <= 9 && b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
        //@ assert result == (((a) <= 9 && (b) <= 9) ? (a) * (b) : -1);
        return result;
    }
}
