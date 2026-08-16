#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= d <= 20;
    ensures \result == (d <= (n / 2 + 1));
*/
bool func(unsigned int n, unsigned int d)
{
    unsigned int half_plus_one;
    bool result;

    half_plus_one = (n / 2) + 1;
    if (d > half_plus_one)
    {
        result = false;
        //@ assert !((d) <= ((n) / 2 + 1));
        return result;
    }
    else
    {
        //@ assert ((d) <= ((n) / 2 + 1));
        result = true;
        return result;
    }
}
