#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0);
    ensures \result == (((a) & (b)) != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations
    bool result;

    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert (a & b) == ((a) & (b));

    result = (a & b) != 0;
    return result;
}
