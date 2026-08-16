#include <limits.h>

/*@
    requires ((length) >= 0 && (width) >= 0);
    requires ((length) + (width) <= INT_MAX / 2);
    ensures ((\result) == 2 * ((length) + (width)));
    assigns \nothing;
*/
int rectangle_perimeter(int length, int width)
{
    // Variable declarations at top of scope
    int ret;

    //@ assert ((length) >= 0 && (width) >= 0);
    //@ assert ((length) + (width) <= INT_MAX / 2);
    //@ assert 2 * (length + width) >= 0;
    //@ assert 2 * (length + width) <= INT_MAX;

    ret = 2 * (length + width);
    return ret;
}
