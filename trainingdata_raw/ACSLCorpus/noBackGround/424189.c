#include <stdint.h>

/*@
    requires ((uint64_t)(side) * (uint64_t)(side) * (uint64_t)(side) <= 0xFFFFFFFF);
    ensures \result == side * side * side;
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t side)
{
    //@ assert ((uint64_t)(side) * (uint64_t)(side) * (uint64_t)(side) <= 0xFFFFFFFF);
    //@ assert (uint64_t)side * (uint64_t)side <= 0xFFFFFFFF;
    //@ assert ((uint64_t)(side) * (uint64_t)(side) * (uint64_t)(side) <= 0xFFFFFFFF);
    return side * side * side;
}

/*@
    requires ((uint64_t)(side) * (uint64_t)(side) * 6 <= 0xFFFFFFFF);
    ensures \result == side * side * 6;
    assigns \nothing;
*/
uint32_t surface_area_cube(uint32_t side)
{
    //@ assert ((uint64_t)(side) * (uint64_t)(side) * 6 <= 0xFFFFFFFF);
    //@ assert (uint64_t)side * (uint64_t)side <= 0xFFFFFFFF;
    //@ assert ((uint64_t)(side) * (uint64_t)(side) * 6 <= 0xFFFFFFFF);
    return side * side * 6;
}
