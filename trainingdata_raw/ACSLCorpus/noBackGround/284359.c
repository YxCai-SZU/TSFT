#include <stdint.h>

/*@
    requires (0 <= (side) <= 1290);
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t side) {
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert side <= 1290;
    
    //@ assert side * side <= 1290 * 1290;
    
    //@ assert side * side * side <= 1290 * 1290 * 1290;
    
    result = side * side * side;
    
    //@ assert result == ((side) * (side) * (side));
    
    return result;
}
