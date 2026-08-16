#include <stdint.h>

/*@
    requires (1 <= (N) && (N) <= 100000);
    assigns \nothing;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((N) % 100) * 21 <= N;
    ensures \result == 0 ==> ((N) % 100) * 21 > N;
*/
int32_t func(uint32_t N)
{
    int32_t n_mod_100;
    int32_t result;

    n_mod_100 = (int32_t)(N % 100);
    //@ assert n_mod_100 >= 0 && n_mod_100 <= 100;

    //@ assert n_mod_100 * 21 <= 100 * 21;

    if (n_mod_100 * 21 <= (int32_t)N)
    {
        //@ assert n_mod_100 * 21 <= N;
        result = 1;
    }
    else
    {
        //@ assert n_mod_100 * 21 > N;
        result = 0;
    }

    return result;
}
