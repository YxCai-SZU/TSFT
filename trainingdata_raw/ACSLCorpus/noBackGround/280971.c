#include <stdbool.h>

/*@
    requires (0 <= (side) <= 1000);
    ensures \result == ((side) * (side) * (side));
*/
int compute_volume_cube(int side) {
    int result;
    //@ assert (0 <= (side) <= 1000);
    result = side * side * side;
    //@ assert result == ((side) * (side) * (side));
    return result;
}

int main() {
    return 0;
}
