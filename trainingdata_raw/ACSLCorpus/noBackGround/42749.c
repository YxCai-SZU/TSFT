#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    ensures \result == ((((n)) / 2) * ((((n)) + 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t n_div_2;
    uint64_t n_plus_1_div_2;
    uint64_t result;

    n_div_2 = n / 2;
    n_plus_1_div_2 = (n + 1) / 2;

    //@ assert n_div_2 == n / 2;
    //@ assert n_plus_1_div_2 == (n + 1) / 2;

    //@ assert n_div_2 <= 50 && n_plus_1_div_2 <= 50;
    //@ assert n_div_2 * n_plus_1_div_2 <= 2500;

    //@ assert n_div_2 * n_plus_1_div_2 == ((((n)) / 2) * ((((n)) + 1) / 2));

    result = n_div_2 * n_plus_1_div_2;
    return result;
}
