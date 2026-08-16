#include <stdint.h>

/*@
    requires ((a) >= 0) && ((b) >= 0) && ((c) >= 0);
    requires (1 <= (k) && (k) <= 200);
    ensures \result <= a;
    ensures ((\result) >= 0);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int32_t a_local = a;
    int64_t k_local = k;
    int32_t b_local;
    int32_t c_local;
    int32_t result;

    // First subtraction from a
    if (k_local > (int64_t)a_local)
    {
        k_local = k_local - (int64_t)a_local;
        a_local = 0;
    }
    else
    {
        a_local = a_local - (int32_t)k_local;
        k_local = 0;
    }

    // Second subtraction from b
    b_local = b;
    if (k_local > (int64_t)b_local)
    {
        k_local = k_local - (int64_t)b_local;
        b_local = 0;
    }
    else
    {
        b_local = b_local - (int32_t)k_local;
        k_local = 0;
    }

    // Third subtraction from c
    c_local = c;
    if (k_local > (int64_t)c_local)
    {
        k_local = k_local - (int64_t)c_local;
        c_local = 0;
    }
    else
    {
        c_local = c_local - (int32_t)k_local;
        k_local = 0;
    }

    // Calculate result
    result = a_local - c_local;
    if (result < 0)
    {
        result = 0;
    }

    // Critical verification properties
    //@ assert result <= a_local;
    //@ assert result >= 0;

    return result;
}
