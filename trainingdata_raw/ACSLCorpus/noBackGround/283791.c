#include <stdbool.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (r) <= 100);
    //@ assert 1 <= ((r) * (r)) && ((r) * (r)) <= 10000;
    //@ assert ((r) * (r)) <= 10000;

    result = r * r;
    //@ assert result == ((r) * (r));
    return result;
}
