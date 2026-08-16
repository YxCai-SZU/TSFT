#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t ans;
    uint64_t discount;
    uint64_t result;

    ans = n * 800;
    //@ assert ans == n * 800;

    discount = (n / 15) * 200;
    //@ assert discount == (n / 15) * 200;

    result = ans - discount;
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);

    return result;
}
