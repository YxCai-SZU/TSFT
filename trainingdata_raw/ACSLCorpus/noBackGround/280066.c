#include <limits.h>

/*@
    requires ((side) >= 0) && ((side) * (side) * (side) <= INT_MAX);
    ensures \result == side * side * side;
    assigns \nothing;
*/
int volume_cube(int side)
{
    // Variable declarations at top of scope
    int ret;

    //@ assert side >= 0 && side <= 1290;
    //@ assert side * side >= 0 && side * side <= 1664100;
    //@ assert side * side * side >= 0 && side * side * side <= INT_MAX;

    ret = side * side * side;
    return ret;
}
