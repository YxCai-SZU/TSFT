#include <stdint.h>

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side)
{
    int32_t ret;
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0;
    //@ assert side * side * side <= 2147483647;
    ret = side * side * side;
    return ret;
}

/*@
    requires (0 <= (side) <= 1000);
    ensures \result == (6 * (side) * (side));
    assigns \nothing;
*/
int32_t surface_area_cube(int32_t side)
{
    int32_t ret;
    //@ assert 6 * side * side >= 0;
    //@ assert 6 * side * side <= 6000000;
    ret = 6 * side * side;
    return ret;
}
