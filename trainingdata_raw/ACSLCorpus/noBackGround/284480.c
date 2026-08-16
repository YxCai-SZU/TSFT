#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures (((\result) == 1) ==> ((n) % 100 >= 5) &&
        ((\result) == 0) ==> ((n) % 100 < 5));
 */
uint32_t func(uint32_t n)
{
    uint32_t n_mod_100;
    uint32_t res;

    n_mod_100 = n % 100;

    if (n_mod_100 < 5)
    {
        //@ assert n_mod_100 < 5;
        res = 0;
    }
    else
    {
        //@ assert n_mod_100 >= 5;
        res = 1;
    }

    //@ assert (((res) == 1) ==> ((n) % 100 >= 5) &&         ((res) == 0) ==> ((n) % 100 < 5));
    return res;
}
