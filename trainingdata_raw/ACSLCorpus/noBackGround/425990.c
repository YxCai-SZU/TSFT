#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000000000);
    ensures \result <= (2 * ((x) / 11) + 2);
    ensures \result >= 0;
*/
uint64_t func(uint64_t x)
{
    uint64_t years;
    uint64_t remaining_months;
    uint64_t min_operations;
    uint64_t result;

    years = x / 11;
    remaining_months = x % 11;
    min_operations = 2 * years;

    //@ assert years == x / 11;
    //@ assert remaining_months == x % 11;
    //@ assert min_operations == 2 * years;

    if (remaining_months > 0)
    {
        if (remaining_months <= 6)
        {
            //@ assert min_operations + 1 <= (2 * ((x) / 11) + 2);
            result = min_operations + 1;
        }
        else
        {
            //@ assert min_operations + 2 <= (2 * ((x) / 11) + 2);
            result = min_operations + 2;
        }
    }
    else
    {
        //@ assert min_operations <= (2 * ((x) / 11) + 2);
        result = min_operations;
    }

    //@ assert result >= 0;
    return result;
}
