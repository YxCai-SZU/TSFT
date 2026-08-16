#include <stdint.h>

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side)
{
    // Declare all variables at the top
    int32_t result;
    
    //@ assert 0 <= side;
    //@ assert side <= 1290;
    //@ assert side * side <= 1290 * 1290;
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    
    result = side * side * side;
    
    //@ assert result == ((side) * (side) * (side));
    return result;
}
