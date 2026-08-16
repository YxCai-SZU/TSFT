#include <stdint.h>

/*@
    requires (0 <= (side) <= 46340);
    ensures \result == ((side) * (side));
    ensures \result >= 0;
*/
int32_t square_area(int32_t side) {
    // Variable declarations at top of scope
    int32_t ret;
    
    //@ assert side >= 0 && side <= 46340;
    
    ret = side * side;
    
    //@ assert ret == side * side;
    //@ assert ret >= 0;
    
    return ret;
}
