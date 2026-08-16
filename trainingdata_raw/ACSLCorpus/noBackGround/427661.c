#include <stdint.h>

/*@
    requires (0 <= (side) <= 1000);
    ensures \result == side * side;
    assigns \nothing;
*/
int32_t square_area(int32_t side) {
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert side * side <= 1000 * 1000;
    
    result = side * side;
    return result;
}

