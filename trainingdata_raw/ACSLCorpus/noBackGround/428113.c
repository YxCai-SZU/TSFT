#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= n <= 1;
    ensures ((n) == 1) ==> \result == 0;
    ensures ((n) == 0) ==> \result == 1;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res;

    if (n == 1)
    {
        //@ assert ((n) == 1);
        res = 0;
    }
    else
    {
        //@ assert ((n) == 0);
        res = 1;
    }

    return res;
}
