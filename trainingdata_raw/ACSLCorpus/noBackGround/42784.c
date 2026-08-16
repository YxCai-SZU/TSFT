#include <stdbool.h>

/*@
    requires \true;
    ensures \result == (a >= 0);
    assigns \nothing;
*/
bool func(int a)
{
    bool is_non_negative;
    //@ assert a >= 0 || a < 0;
    is_non_negative = (a >= 0);
    return is_non_negative;
}
