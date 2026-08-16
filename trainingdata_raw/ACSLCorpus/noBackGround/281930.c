#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 100 && 1 <= (b) <= 2000);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t ans;
    uint64_t product;

    product = n * a;

    //@ assert (1 <= (n) <= 20 && 1 <= (a) <= 100 && 1 <= (b) <= 2000);
    //@ assert product <= 2000;

    if (product < b)
    {
        ans = product;
        //@ assert ans == n * a;
    }
    else
    {
        ans = b;
        //@ assert ans == b;
    }

    //@ assert ans <= b;
    return ans;
}
