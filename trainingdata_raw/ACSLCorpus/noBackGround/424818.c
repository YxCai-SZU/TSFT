#include <limits.h>

/*@
    requires ((side) >= 0);
    requires ((side) * (side) * (side) <= INT_MAX);
    ensures ((\result) == (side) * (side) * (side));
*/
int volume_cube(int side)
{
    // Variable declarations at top of scope
    int result;

    //@ assert side >= 0;
    //@ assert side * side * side <= INT_MAX;
    //@ assert side * side >= 0 && side * side <= 1664100;
    //@ assert side * side * side >= 0 && side * side * side <= INT_MAX;

    result = side * side * side;
    return result;
}
