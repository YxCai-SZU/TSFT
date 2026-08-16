#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 255);
    ensures \result == (((n) * ((n) + 1) * ((n) + 2)) / 6);
    assigns \nothing;
*/
uint32_t tetrahedral_number(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t product1;
    uint32_t product2;
    uint32_t result;

    //@ assert 0 <= n && n <= 255;
    
    product1 = n * (n + 1);
    //@ assert product1 <= 255 * 256;
    
    product2 = product1 * (n + 2);
    //@ assert product2 <= 255 * 256 * 257;
    
    result = product2 / 6;
    //@ assert result == (((n) * ((n) + 1) * ((n) + 2)) / 6);
    
    return result;
}
