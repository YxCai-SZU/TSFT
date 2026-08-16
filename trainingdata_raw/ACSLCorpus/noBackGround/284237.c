#include <stddef.h>

/*@
    requires 1 <= n && n <= 100000;
    ensures \result == (n % 1000 == 0 ? 0 : 1000 - (n % 1000));
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t change;

    //@ assert (1 <= (n) && (n) <= 100000);
    
    if (n % 1000 == 0)
    {
        //@ assert n % 1000 == 0;
        change = 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        change = 1000 - (n % 1000);
    }

    //@ assert change == ((n) % 1000 == 0 ? 0 : 1000 - ((n) % 1000));
    return change;
}
