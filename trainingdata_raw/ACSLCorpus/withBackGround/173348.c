#include <stdint.h>

/*@ predicate is_even(integer x) = x % 2 == 0; */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 && is_even(a + b) || \result == 1 && !is_even(a + b);
*/
int32_t func(uint64_t a, uint64_t b)
{
    uint64_t sum;
    int32_t result;

    sum = a + b;
    if (sum % 2 == 0)
    {
        result = 0;
        //@ assert is_even(a + b);
    }
    else
    {
        //@ assert !is_even(a + b);
        result = 1;
    }
    return result;
}
