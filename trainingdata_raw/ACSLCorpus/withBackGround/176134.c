#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    predicate result_range(integer r) =
        1 <= r && r <= 3;
*/

/*@
    requires valid_input(a, b, c);
    ensures result_range(\result);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t temp;
    int32_t result;

    //@ assert valid_input(a, b, c);

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result_range(result);
        return result;
    }
    else if (a == b || b == c || c == a)
    {
        result = 2;
        //@ assert result_range(result);
        return result;
    }
    else
    {
        x = a;
        y = b;
        z = c;

        // Bubble sort implementation
        if (x > y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        //@ assert x <= y;

        if (y > z)
        {
            temp = y;
            y = z;
            z = temp;
        }
        //@ assert y <= z;

        if (x > y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        //@ assert x <= y && y <= z;

        if (x + y < z)
        {
            //@ assert x + y < z;
            result = 3;
            //@ assert result_range(result);
            return result;
        }
        else
        {
            //@ assert x + y >= z;
            result = 2;
            //@ assert result_range(result);
            return result;
        }
    }
}
