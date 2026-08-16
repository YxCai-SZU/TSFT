#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100000);
    ensures \result == (a >= 2000 || (100 * (a / 100) <= a && a <= 105 * (a / 100)));
    assigns \nothing;
*/
bool func(unsigned long long a)
{
    unsigned long long n;
    unsigned long long m;
    bool result;

    n = a / 100;
    m = a - 100 * n;

    if (a >= 2000)
    {
        //@ assert a >= 2000;
        return true;
    }

    if (100 * n <= a && a <= 105 * n)
    {
        //@ assert 100 * (a / 100) <= a && a <= 105 * (a / 100);
        return true;
    }
    else
    {
        //@ assert !(a >= 2000 || (100 * (a / 100) <= a && a <= 105 * (a / 100)));
        return false;
    }
}
