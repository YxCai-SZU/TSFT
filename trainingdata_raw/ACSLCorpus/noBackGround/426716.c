#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n >= 90);
*/
bool func(int n)
{
    unsigned int n_unsigned;
    unsigned int last_digit;
    bool greater_or_equal_90;
    bool result;

    n_unsigned = (unsigned int)n;
    last_digit = n_unsigned % 10;
    greater_or_equal_90 = n_unsigned >= 90;

    if (last_digit == 9 || greater_or_equal_90)
    {
        //@ assert n_unsigned % 10 == 9 || n_unsigned >= 90;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
