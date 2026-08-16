#include <stdint.h>

/*@
    requires (0 <= (a) <= 50 && 0 <= (b) <= 50 && 0 <= (c) <= 50);
    ensures \result >= 0;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min_val;
    int64_t result;
    int64_t extra;

    min_val = a;
    //@ assert min_val == a;
    if (b < min_val)
    {
        min_val = b;
    }
    //@ assert min_val <= a && min_val <= b;
    if (c < min_val)
    {
        min_val = c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;

    result = min_val;
    extra = b - min_val;
    //@ assert extra == b - min_val;

    if (extra < min_val)
    {
        result += extra;
        //@ assert result == min_val + extra;
    }
    else
    {
        result += min_val;
        //@ assert result == min_val + min_val;
    }

    int64_t temp = c - min_val;
    if (extra < min_val)
    {
        temp -= extra;
    }
    else
    {
        temp -= min_val;
    }

    if (temp < min_val)
    {
        result += temp;
    }
    else
    {
        result += min_val;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;
    return result;
}
