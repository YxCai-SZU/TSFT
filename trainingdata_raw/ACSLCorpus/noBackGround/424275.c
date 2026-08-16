#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000000000000000);
    ensures \result == (((((x)) / 100) * 100) <= x);
    assigns \nothing;
*/
bool func(unsigned long long x)
{
    unsigned long long x_100;
    unsigned long long x_100_back;
    bool result;

    x_100 = x / 100;
    x_100_back = x_100 * 100;

    //@ assert x_100_back == ((((x)) / 100) * 100);
    //@ assert ((((x)) / 100) * 100) == (x / 100) * 100;

    result = x_100_back <= x;
    return result;
}
