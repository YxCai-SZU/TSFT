#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n) {
    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert ((n) * (n)) <= 10000;
    return n * n;
}

/*@
    requires (0 <= (side) && (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side) {
    //@ assert (0 <= (side) && (side) <= 1290);
    //@ assert side * side >= 0 && side * side <= 1290 * 1290;
    //@ assert ((side) * (side) * (side)) >= 0;
    //@ assert ((side) * (side) * (side)) <= 1290 * 1290 * 1290;
    return side * side * side;
}
