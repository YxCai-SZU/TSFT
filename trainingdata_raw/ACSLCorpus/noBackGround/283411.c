#include <stdbool.h>

/*@
    requires x >= 0;
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int x)
{
    //@ assert x >= 0 && x <= 4294967295;
    //@ assert x % 2 == x % 2;
    return x % 2 != 0;
}
