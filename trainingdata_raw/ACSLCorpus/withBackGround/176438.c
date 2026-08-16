#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 100;

    logic integer safe_sub(integer x, integer y) = x >= y ? x - y : 0;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t sum;
    int32_t result;

    sum = a + b;

    //@ assert sum >= -200 && sum <= 200;

    if (sum >= 0)
    {
        if (sum <= 100)
        {
            result = sum;
        }
        else
        {
            result = 100;
        }
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0 && result <= 100;

    if (result == 0)
    {
        return 0;
    }
    else if (result == 100)
    {
        return a;
    }
    else
    {
        //@ assert result >= b;
        //@ assert result - b >= 0;
        //@ assert a >= result - b;
        return a - (result - b);
    }
}
