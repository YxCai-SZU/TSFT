#include <stdbool.h>

/*@
    requires a >= 10;
    ensures \result == true;
    assigns \nothing;
*/
bool func(unsigned int a)
{
    //@ assert ((a) >= 0);
    //@ assert a >= 10;
    //@ assert (a & 0x1) == (a & 1);
    return true;
}
