#include <stdint.h>

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0;
    //@ assert side * side * side <= 1290 * 1290 * 1290;

    result = side * side * side;
    return result;
}
