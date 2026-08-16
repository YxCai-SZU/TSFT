#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == ((((p)) + ((a)) * 3) / 2);
    ensures \result <= ((p) + (a) * 3);
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t total_pieces;
    uint32_t pies;

    total_pieces = p + a * 3;
    //@ assert total_pieces == ((p) + (a) * 3);
    
    pies = total_pieces / 2;
    //@ assert pies == ((((p)) + ((a)) * 3) / 2);
    
    return pies;
}
