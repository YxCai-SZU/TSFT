#include <stdint.h>

/*@
    requires (0 <= (x) <= 16) && (0 <= (y) <= 16);
    ensures \result == ((((x)) * ((x)) * ((x))) + (((y)) * ((y)) * ((y))));
    assigns \nothing;
*/
uint32_t sum_cubes(uint32_t x, uint32_t y) {
    // Variable declarations at top of scope
    uint32_t x_cube;
    uint32_t y_cube;
    
    //@ assert 0 <= x * x * x <= 16 * 16 * 16;
    //@ assert 0 <= y * y * y <= 16 * 16 * 16;
    //@ assert 0 <= x * x <= 16 * 16;
    //@ assert 0 <= y * y <= 16 * 16;
    
    x_cube = x * x * x;
    y_cube = y * y * y;
    
    return x_cube + y_cube;
}

int main() {
    return 0;
}
