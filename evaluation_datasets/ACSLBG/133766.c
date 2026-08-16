#include <stdint.h>

/*@
    predicate is_small(integer x) = 1 <= x <= 9;
    predicate is_medium(integer x) = 1 <= x <= 20;
*/


int32_t func(int32_t a, int32_t b)
{
    int32_t result;
    int32_t i;

    if (a > 9 || b > 9)
    {
        //@ assert !(is_small(a) && is_small(b));
        result = -1;
        return result;
    }

    i = 0;
    
    while (i < a)
    {
        i = i + 1;
    }

    //@ assert is_small(a) && is_small(b);
    //@ assert a * b <= 81;
    result = a * b;
    return result;
}
