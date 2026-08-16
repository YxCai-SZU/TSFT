#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 100 * 21 <= n;
    ensures \result == 0 ==> n % 100 * 21 > n;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t x;
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 100000);
    x = n / 100 + (n % 100 != 0 ? 1 : 0);

    if (n % 100 * 21 <= n)
    {
        //@ assert n % 100 * 21 <= n;
        result = 1;
    }
    else
    {
        //@ assert n % 100 * 21 > n;
        result = 0;
    }

    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> n % 100 * 21 <= n;
    //@ assert result == 0 ==> n % 100 * 21 > n;
    return result;
}
