#include <stdint.h>

/*@
    requires ((l) >= 0 && (l) <= 1290);
    ensures \result == l * l * l;
    assigns \nothing;
*/
int32_t volume_cube(int32_t l)
{
    // Variable declarations at the top
    int32_t result;

    //@ assert ((l) >= 0);
    //@ assert ((l) * (l) >= 0 && (l) * (l) <= 1290 * 1290);
    //@ assert ((l) * (l) * (l) >= 0 && (l) * (l) * (l) <= 1290 * 1290 * 1290);
    
    result = l * l * l;
    return result;
}
