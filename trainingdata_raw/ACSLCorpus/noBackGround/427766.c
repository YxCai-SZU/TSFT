#include <stdbool.h>

/*@
    requires side > 0;
    ensures \result == ((side) > 0 ? (side) * (side) * (side) : 0);
    ensures \result > 0;
*/
int compute_volume_cube(int side) {
    int volume;
    
    //@ assert ((side) > 0);
    
    volume = side * side * side;
    
    //@ assert volume == ((side) > 0 ? (side) * (side) * (side) : 0);
    //@ assert volume > 0;
    
    return volume;
}

int main() {
    int result;
    
    result = compute_volume_cube(3);
    
    //@ assert result == 27;
    
    return 0;
}
