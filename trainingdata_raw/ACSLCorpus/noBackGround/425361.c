#include <stdbool.h>

/*@
    requires (1 <= (m) <= 23);
    ensures \result == (48 - (m));
    assigns \nothing;
*/
int func(int m)
{
    int res;

    //@ assert (48 - (m)) == (48 - (m));

    res = 48 - m;
    return res;
}
