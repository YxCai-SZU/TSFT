#include <stdbool.h>

/*@
    requires \true;
    ensures \result == ((n & 1) == 0);
    assigns \nothing;
*/
bool is_even(int n)
{
    bool ret;
    //@ assert (n & 1) == (n & 1);
    ret = ((n & 1) == 0);
    return ret;
}
