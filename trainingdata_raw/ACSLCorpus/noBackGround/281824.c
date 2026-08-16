#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert n * 800 <= 100 * 800;
    //@ assert (n / 15) * 200 <= 100 * 200;
    //@ assert n * 800 >= (n / 15) * 200;

    result = (int32_t)(n * 800 - (n / 15) * 200);
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);
    return result;
}
