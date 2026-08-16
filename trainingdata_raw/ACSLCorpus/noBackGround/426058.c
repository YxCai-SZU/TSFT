#include <stdint.h>

/*@
    requires side >= 0 && side < 0x80000000;
    ensures \result == ((side) * (side) * (side));
    assigns \nothing;
*/
int32_t compute_cube_volume(int32_t side) {
    int32_t result;
    
    //@ assert side >= 0 && side < 0x80000000;
    result = side * side * side;
    
    //@ assert result == ((side) * (side) * (side));
    return result;
}

int main() {
    return 0;
}
