#include <stdbool.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == (n >= 2000 || n % 200 == 0);
    ensures ((\result) == ((n) >= 2000 || (n) % 200 == 0));
*/
bool func(unsigned int n)
{
    unsigned int n_mod_200;
    unsigned int n_div_200;
    bool result;

    n_mod_200 = n % 200;
    n_div_200 = n / 200;

    //@ assert n_mod_200 == n % 200;
    //@ assert n_div_200 == n / 200;

    result = (n >= 2000) || (n_mod_200 == 0);
    return result;
}
