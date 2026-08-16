#include <stdbool.h>

/*@
    requires \true;
    ensures \result == (x % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int x)
{
    //@ assert x % 2 == x % 2;
    return x % 2 != 0;
}
