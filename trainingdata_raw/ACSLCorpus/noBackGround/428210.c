#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    ensures \result == ((((n)) / 2) * ((((n)) + 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t half_n;
    uint64_t half_n_plus_one;
    uint64_t ans;

    //@ assert (2 <= (n) && (n) <= 100);
    half_n = n / 2;
    half_n_plus_one = (n + 1) / 2;

    //@ assert 1 <= half_n && half_n <= 50;
    //@ assert 1 <= half_n_plus_one && half_n_plus_one <= 50;
    //@ assert half_n * half_n_plus_one <= 2500;

    ans = half_n * half_n_plus_one;
    //@ assert ans == ((((n)) / 2) * ((((n)) + 1) / 2));
    return ans;
}
