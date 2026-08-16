#include <stdint.h>

/*@
    requires (0 <= (side) <= 1000);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t side)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert side <= 1000;
    
    //@ assert side * side >= 0;
    //@ assert side * side * side >= 0;
    
    //@ assert side * side <= 1000 * 1000;
    //@ assert side * side * side <= 1000 * 1000 * 1000;
    
    result = side * side * side;
    
    //@ assert result == ((side) * (side) * (side));
    
    return result;
}
