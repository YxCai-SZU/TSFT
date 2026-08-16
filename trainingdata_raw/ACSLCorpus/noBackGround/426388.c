#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == 1 || \result == 2 || \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t max_value;
    uint32_t min_value;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    if (a > b)
    {
        max_value = a;
        min_value = b;
    }
    else
    {
        max_value = b;
        min_value = a;
    }

    //@ assert max_value == ((a) > (b) ? (a) : (b));
    //@ assert min_value == ((a) < (b) ? (a) : (b));

    if (c <= min_value && min_value * 2 <= d)
    {
        //@ assert c <= min_value && min_value * 2 <= d;
        return 1;
    }
    else if (d <= max_value + min_value)
    {
        //@ assert d <= max_value + min_value;
        return 2;
    }
    else
    {
        return 0;
    }
}
