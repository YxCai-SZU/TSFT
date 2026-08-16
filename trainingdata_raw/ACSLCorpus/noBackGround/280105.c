#include <limits.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at the top
    int result;

    //@ assert b - 1 >= 1;
    //@ assert a - 1 >= 1;
    //@ assert (((a) - 1) * ((b) - 1)) <= 99 * 99;
    //@ assert (((a) - 1) * ((b) - 1)) >= 1 * 1;

    result = (a - 1) * (b - 1);
    return result;
}
