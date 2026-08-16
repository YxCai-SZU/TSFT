#include <stdint.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b) {
    int32_t res;
    //@ assert (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    res = 6 - a - b;
    //@ assert res == (6 - (a) - (b));
    return res;
}

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side) {
    int32_t ret;
    //@ assert (0 <= (side) <= 1290);
    //@ assert side * side >= 0 && side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0 && side * side * side <= 1290 * 1290 * 1290;
    ret = side * side * side;
    //@ assert ret == ((side) * (side) * (side));
    return ret;
}

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube_safe(int32_t side) {
    int32_t ret;
    //@ assert (0 <= (side) <= 1290);
    //@ assert side * side >= 0 && side * side <= 1290 * 1290;
    //@ assert side * side * side >= 0 && side * side * side <= 1290 * 1290 * 1290;
    ret = side * side * side;
    //@ assert ret == ((side) * (side) * (side));
    return ret;
}
