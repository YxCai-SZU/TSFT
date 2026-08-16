#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t r)
{
    uint64_t ans;

    //@ assert (1 <= (n) <= 100 && 0 <= (r) <= 4111);

    if (n >= 10)
    {
        ans = r;
        //@ assert ans == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    }
    else
    {
        //@ assert n < 10;
        //@ assert 10 - n <= 10;
        //@ assert 100 * (10 - n) <= 1000;
        //@ assert r + 100 * (10 - n) <= 4111 + 1000;
        ans = r + 100 * (10 - n);
        //@ assert ans == ((n) >= 10 ? (r) : (r) + 100 * (10 - (n)));
    }

    return ans;
}
