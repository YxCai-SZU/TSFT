#include <stdint.h>

/*@
    requires (0 <= (l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t l)
{
    // Declare all variables at the top
    uint32_t result;

    //@ assert l <= 1290;
    //@ assert l * l <= 1290 * 1290;
    //@ assert l * l * l <= 1290 * 1290 * 1290;
    
    result = l * l * l;
    //@ assert result == ((l) * (l) * (l));
    
    return result;
}
