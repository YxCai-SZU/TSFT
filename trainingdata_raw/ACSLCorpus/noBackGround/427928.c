#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures
        (((n) % 100) < 10) ==> \result == 0 &&
        (10 <= ((n) % 100) && ((n) % 100) <= 99) ==> \result == 1 &&
        (((n) % 100) > 99) ==> \result == 2;
*/
int32_t func(uint32_t n) {
    uint32_t n_mod_100;
    int32_t ret;

    n_mod_100 = n % 100;

    //@ assert n_mod_100 == ((n) % 100);

    if (n_mod_100 < 10) {
        //@ assert n_mod_100 < 10;
        ret = 0;
    } else if (n_mod_100 <= 99) {
        //@ assert n_mod_100 >= 10 && n_mod_100 <= 99;
        ret = 1;
    } else {
        //@ assert n_mod_100 > 99;
        ret = 2;
    }

    return ret;
}
