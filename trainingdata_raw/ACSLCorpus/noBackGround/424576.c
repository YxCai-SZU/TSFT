#include <stdint.h>

/*@
    requires (0 <= (a) && (a) < 100000000000000000) && (0 <= (b) && (b) < 100000000000000000);
    ensures (0 <= (\result) && (\result) < 100000000000000000);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    uint64_t result;
    uint64_t remainder;

    sum = a + b;
    result = sum / 9;
    remainder = sum % 9;

    //@ assert (0 <= (a) && (a) < 100000000000000000) && (0 <= (b) && (b) < 100000000000000000);
    
    if (remainder > 0)
    {
        result = result + 1;
    }

    //@ assert (0 <= (result) && (result) < 100000000000000000);
    return result;
}
