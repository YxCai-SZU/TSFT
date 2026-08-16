#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100);
    ensures \result == (((n) / 2) * (((n) + 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 1 <= n/2 && n/2 <= 50;
    //@ assert 1 <= (n+1)/2 && (n+1)/2 <= 50;
    //@ assert (n/2) * ((n+1)/2) <= 2500;

    result = (n / 2) * ((n + 1) / 2);
    //@ assert result == (((n) / 2) * (((n) + 1) / 2));
    return result;
}
