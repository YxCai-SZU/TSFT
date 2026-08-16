#include <stdbool.h>

/*@
    requires side > 0;
    ensures \result == ((side) <= 0 ? 0 :
        (side) == 1 ? 1 :
        (side) * (side) * (side));
    ensures \result > 0;
*/
int compute_cube_volume(int side) {
    int volume;
    
    //@ assert side > 0;
    
    if (side <= 0) {
        volume = 0;
    } else if (side == 1) {
        volume = 1;
    } else {
        volume = side * side * side;
    }
    
    //@ assert volume == ((side) <= 0 ? 0 :         (side) == 1 ? 1 :         (side) * (side) * (side));
    //@ assert volume > 0;
    
    return volume;
}

int main() {
    int result = compute_cube_volume(3);
    return 0;
}
