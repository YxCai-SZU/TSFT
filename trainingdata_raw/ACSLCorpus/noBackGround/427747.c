#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures ((n) < 10 && (m) < 10) ==> \result == 1;
    ensures ((n) >= 10 || (m) >= 10) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    int32_t result;

    if (n >= 10 || m >= 10)
    {
        result = 0;
        //@ assert ((n) >= 10 || (m) >= 10);
    }
    else
    {
        //@ assert ((n) < 10 && (m) < 10);
        //@ assert n * m <= 100;
        result = 1;
    }

    return result;
}
