#include <stdint.h>

/*@
    requires ((l) >= 0 && (l) <= 1290);
    ensures \result == ((l) * (l) * (l));
    assigns \nothing;
*/
int32_t volume_cube(int32_t l)
{
    // Variable declarations at scope top
    int32_t ret;

    //@ assert ((l) >= 0 && (l) <= 1290);
    //@ assert l * l >= 0 && l * l <= 1290 * 1290;
    //@ assert l * l * l >= 0 && l * l * l <= 1290 * 1290 * 1290;
    
    ret = l * l * l;
    //@ assert ret == ((l) * (l) * (l));
    return ret;
}
