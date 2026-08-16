#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result == (((n) > 1 && (m) > 1) ? ((n) - 2) * ((m) - 2) : 0);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at scope top
    int64_t result;

    //@ assert n >= 1 && n <= 100;
    //@ assert m >= 1 && m <= 100;
    //@ assert n - 2 >= -1 && n - 2 <= 98;
    //@ assert m - 2 >= -1 && m - 2 <= 98;

    if (n > 1 && m > 1)
    {
        result = (n - 2) * (m - 2);
    }
    else
    {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result == (((n) > 1 && (m) > 1) ? ((n) - 2) * ((m) - 2) : 0);
    return result;
}
