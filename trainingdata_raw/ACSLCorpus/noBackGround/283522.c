#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures 0 <= \result <= 1000;
    ensures \result == (n + 999) / 1000 * 1000 - n;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;

    if (n % 1000 != 0)
    {
        ans = (n / 1000 + 1) * 1000;
        //@ assert ans == (n / 1000 + 1) * 1000;
    }
    else
    {
        ans = n;
        //@ assert ans == n;
    }

    //@ assert ans == (((n) % 1000 != 0) ?         (((n) / 1000 + 1) * 1000) :         (n));
    //@ assert ans - n == (((((n)) % 1000 != 0) ?         ((((n)) / 1000 + 1) * 1000) :         ((n))) - (n));

    return ans - n;
}
