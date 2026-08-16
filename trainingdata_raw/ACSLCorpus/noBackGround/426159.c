#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((((l)) / 3) * (((l)) / 3) * (((l)) / 3));
    assigns \nothing;
*/
uint64_t func(uint64_t l)
{
    uint64_t l_div_3;
    uint64_t res;

    l_div_3 = l / 3;
    //@ assert l_div_3 == ((l) / 3);

    //@ assert l_div_3 <= 333;
    //@ assert l_div_3 * l_div_3 <= 333 * 333;
    //@ assert l_div_3 * l_div_3 * l_div_3 <= 333 * 333 * 333;

    res = l_div_3 * l_div_3 * l_div_3;
    //@ assert res == ((((l)) / 3) * (((l)) / 3) * (((l)) / 3));
    return res;
}
