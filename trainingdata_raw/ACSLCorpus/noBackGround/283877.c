#include <stdbool.h>

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || (n / 10) % 10 == 9);
    assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int n_mod;
    unsigned int n_div;
    bool result;

    n_mod = n % 10;
    n_div = n / 10;

    if (n_mod == 9 || n_div == 9)
    {
        result = true;
    }
    else
    {
        //@ assert n_mod != 9 && n_div != 9;
        result = false;
    }

    return result;
}
