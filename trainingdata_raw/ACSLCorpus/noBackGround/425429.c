#include <stdint.h>

/*@
    requires (0 <= (n) <= 255);
    ensures \result == (((n) * ((n) + 1) * ((n) + 2)) / 6);
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t tetrahedral;

    //@ assert n <= 255;
    //@ assert n + 1 <= 256;
    //@ assert n + 2 <= 257;
    //@ assert n * (n + 1) <= 255 * 256;
    //@ assert n * (n + 1) * (n + 2) <= 255 * 256 * 257;
    //@ assert (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;

    tetrahedral = n * (n + 1) * (n + 2) / 6;

    //@ assert tetrahedral == (((n) * ((n) + 1) * ((n) + 2)) / 6);
    return tetrahedral;
}
