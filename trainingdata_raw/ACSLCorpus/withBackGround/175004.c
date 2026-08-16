#include <stdint.h>

/*@
    predicate in_range(integer n) = 1 <= n <= 100000;

    logic integer compute_res(integer n_mod_100) =
        n_mod_100 < 5 && n_mod_100 >= 0 ? 0 :
        n_mod_100 >= 5 && n_mod_100 < 10 ? 100 - n_mod_100 :
        500 - n_mod_100 * 10;

    lemma mod_range: \forall integer n; in_range(n) ==> 0 <= n % 100 <= 99;
*/

/*@
    requires in_range(n);
    ensures \result == compute_res(n % 100);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t n_mod_100;
    int32_t res;

    n_mod_100 = n % 100;

    //@ assert 0 <= n_mod_100 <= 99;

    if (n_mod_100 < 5)
    {
        //@ assert n_mod_100 < 5 && n_mod_100 >= 0;
        res = 0;
    }
    else if (n_mod_100 < 10)
    {
        //@ assert n_mod_100 >= 5 && n_mod_100 < 10;
        res = 100 - (int32_t)n_mod_100;
    }
    else
    {
        //@ assert n_mod_100 >= 10;
        res = 500 - (int32_t)n_mod_100 * 10;
    }

    return res;
}
