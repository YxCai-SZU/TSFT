#include <stdbool.h>

/*@
    requires 1 <= a <= 4294967295;
    ensures \result == ((a & 7) == 0);
    assigns \nothing;
 */
bool func(unsigned int a)
{
    bool result;
    //@ assert (a & 7) == 0 ==> (a & 7) == 0;
    result = (a & 7) == 0;
    return result;
}
