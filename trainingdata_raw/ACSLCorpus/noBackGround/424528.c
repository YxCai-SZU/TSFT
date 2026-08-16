#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 >= n;
    ensures \result == 0 ==> (n % 100) * 21 < n;
*/
uint32_t func(uint32_t n)
{
    uint32_t n_div_100;
    uint32_t n_mod_100;
    uint32_t min_val;
    uint32_t ans;

    n_div_100 = n / 100;
    n_mod_100 = n % 100;

    //@ assert n_mod_100 == n % 100;

    if (n_div_100 < 50)
    {
        min_val = n_div_100;
    }
    else
    {
        min_val = 50;
    }

    //@ assert min_val == (n_div_100 < 50 ? n_div_100 : 50);

    if (n_mod_100 * 21 >= n)
    {
        ans = 1;
    }
    else
    {
        ans = 0;
    }

    //@ assert ans == 1 || ans == 0;
    //@ assert ((ans) == 1 ==> ((n) % 100) * 21 >= (n));
    //@ assert ((ans) == 0 ==> ((n) % 100) * 21 < (n));

    return ans;
}
