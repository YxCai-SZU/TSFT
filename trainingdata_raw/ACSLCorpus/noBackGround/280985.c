#include <stdint.h>

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side)
{
    int32_t ret;
    
    //@ assert (0 <= (side) <= 1290);
    //@ assert 0 <= side * side <= 1290 * 1290;
    //@ assert 0 <= side * side * side <= 1290 * 1290 * 1290;
    
    ret = side * side * side;
    
    //@ assert ret == ((side) * (side) * (side));
    return ret;
}
