#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t mo;
    size_t ans;

    mo = n % 1000;

    if (mo == 0)
    {
        return 0;
    }
    else
    {
        ans = 1000 - mo;
        //@ assert ans == 1000 - (n % 1000);
        return ans;
    }
}
