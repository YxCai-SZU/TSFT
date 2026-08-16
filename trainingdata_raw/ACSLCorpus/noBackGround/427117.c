#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert a + b <= 200;
    //@ assert (a + b + 1) / 2 <= 100;

    size_t ans = (a + b + 1) / 2;
    return ans;
}
