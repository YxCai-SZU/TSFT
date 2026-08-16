#include <limits.h>

/*@
    requires INT_MIN <= x <= INT_MAX;
    requires INT_MIN <= y <= INT_MAX;
    ensures (((\result) == (x) || (\result) == (y)) && (\result) <= (x) && (\result) <= (y));
*/
int min_int(int x, int y)
{
    // Variable declarations at top of scope
    int ret;

    //@ assert x >= INT_MIN && x <= INT_MAX;
    //@ assert y >= INT_MIN && y <= INT_MAX;

    if (x < y) {
        //@ assert x <= y;
        ret = x;
    } else {
        //@ assert y <= x;
        ret = y;
    }

    //@ assert (((ret) == (x) || (ret) == (y)) && (ret) <= (x) && (ret) <= (y));
    return ret;
}
