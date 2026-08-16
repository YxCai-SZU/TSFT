#include <stdint.h>

/*@
    requires (0 <= (l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
int32_t volume_cube(int32_t l)
{
    //@ assert (0 <= (l) <= 1290);
    
    int32_t result;
    result = l * l * l;
    
    //@ assert result == ((l) * (l) * (l));
    return result;
}
