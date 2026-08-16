#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (n % 100) * 21 >= n % 100;
    ensures \result == 0 ==> (n % 100) * 21 < n % 100;
*/
int32_t func(uint32_t n) {
    uint32_t n_mod_100;
    uint32_t twenty_one_times;
    int32_t result;

    n_mod_100 = n % 100;
    twenty_one_times = n_mod_100 * 21;

    if (twenty_one_times >= n_mod_100) {
        //@ assert twenty_one_times >= n_mod_100;
        result = 1;
    } else {
        //@ assert twenty_one_times < n_mod_100;
        result = 0;
    }

    return result;
}
