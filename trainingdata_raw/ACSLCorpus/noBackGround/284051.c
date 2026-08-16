#include <stdint.h>

/*@
    requires (0 <= (n) <= 255);
    ensures \result == (((n) * ((n) + 1) * ((n) + 2)) / 6);
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    //@ assert n <= 255;
    //@ assert n + 1 <= 256;
    //@ assert n + 2 <= 257;
    //@ assert n * (n + 1) <= 255 * 256;
    //@ assert n * (n + 1) * (n + 2) <= 255 * 256 * 257;
    //@ assert (n * (n + 1) * (n + 2)) / 6 <= (255 * 256 * 257) / 6;
    
    return (n * (n + 1) * (n + 2)) / 6;
}
