#include <limits.h>

/*@
    requires ((a) <= INT_MAX - (b));
    requires ((a) >= INT_MIN - (b));
    ensures \result == a + b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert ((a) <= INT_MAX - (b));
    //@ assert ((a) >= INT_MIN - (b));
    return a + b;
}
