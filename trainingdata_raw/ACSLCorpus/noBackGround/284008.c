#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    ensures \result == x * 2;
    assigns \nothing;
*/
int func(int x)
{
    //@ assert (1 <= (x) <= 100);
    return x * 2;
}
