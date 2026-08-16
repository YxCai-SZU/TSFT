#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures (n * 2 + 1 <= m) ==> \result == (int)(m - n * 2);
    ensures (n * 2 + 1 > m) ==> \result == 0;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    //@ assert n * 2 + 1 <= 201;
    //@ assert m - n * 2 <= 100;

    if (n * 2 + 1 <= m)
    {
        return (int32_t)(m - n * 2);
    }
    else
    {
        return 0;
    }
}
