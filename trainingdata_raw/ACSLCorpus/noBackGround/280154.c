#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (x >= (((x) / 100) * 100 + ((x) % 100)));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int m;
    bool result;

    n = x / 100;
    m = x % 100;

    //@ assert n * 100 + m == (((x) / 100) * 100 + ((x) % 100));

    result = (x >= (n * 100 + m));
    return result;
}
