#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);
    ensures \result == ((m) >= 2 * (n) ? (m) - 2 * (n) : -1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;

    //@ assert (1 <= (n) && 1 <= (m) && (n) <= 100 && (m) <= 100);

    if (m < 2 * n)
    {
        //@ assert m < 2 * n;
        result = -1;
        //@ assert result == ((m) >= 2 * (n) ? (m) - 2 * (n) : -1);
        return result;
    }

    //@ assert m >= 2 * n;
    result = (int32_t)(m - 2 * n);
    //@ assert result == ((m) >= 2 * (n) ? (m) - 2 * (n) : -1);
    return result;
}
