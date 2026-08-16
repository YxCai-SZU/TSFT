#include <stdint.h>

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    requires 1 <= z <= 100;
    ensures \result == 0;
    ensures x * y <= 10000;
    ensures x * y * z <= 1000000;
*/
int check_bounds(uint32_t x, uint32_t y, uint32_t z) {
    // Variable declarations at scope top
    uint32_t xy;
    uint32_t xyz;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;
    //@ assert 1 <= z <= 100;

    xy = x * y;
    //@ assert xy <= 10000;

    xyz = xy * z;
    //@ assert xyz <= 1000000;

    return 0;
}
