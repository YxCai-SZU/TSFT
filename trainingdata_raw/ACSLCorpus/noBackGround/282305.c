#include <stdbool.h>

/*@
    requires x < 4294967295;
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int x)
{
    //@ assert x < 4294967295;
    return x % 2 != 0;
}
