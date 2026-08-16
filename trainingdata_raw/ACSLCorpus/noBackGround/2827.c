#include <stdint.h>

/*@
    requires 1 <= x && x <= 1000000000000000000;
    ensures \result <= (((x) / 11) * 2 + 2);
*/
uint64_t func(uint64_t x)
{
    uint64_t res_base;
    uint64_t res_add;
    uint64_t x_mod_11;

    res_base = x / 11;
    x_mod_11 = x % 11;

    //@ assert x_mod_11 >= 0 && x_mod_11 <= 10;
    
    if (x_mod_11 == 0) {
        res_add = 0;
    } else if (x_mod_11 <= 5) {
        res_add = 1;
    } else {
        res_add = 2;
    }

    //@ assert (((x_mod_11) == 0 ==> (res_add) == 0) &&         (1 <= (x_mod_11) && (x_mod_11) <= 5 ==> (res_add) == 1) &&         (6 <= (x_mod_11) && (x_mod_11) <= 10 ==> (res_add) == 2));
    //@ assert res_add <= 2;
    //@ assert res_base * 2 + res_add <= (((x) / 11) * 2 + 2);

    return res_base * 2 + res_add;
}
