#include <limits.h>

/*@
    requires ((side) >= 0 && (side) * (side) * (side) <= INT_MAX);
    ensures \result >= 0;
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int volume_cube(int side) {
    int result;
    //@ assert side >= 0 && side <= 1290;
    //@ assert side * side >= 0 && side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0 && side * side * side <= 1290 * 1290 * 1290;
    result = side * side * side;
    return result;
}
