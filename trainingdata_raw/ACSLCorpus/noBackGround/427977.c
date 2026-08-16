#include <stdint.h>

/*@
  requires (0 <= (side) <= 46340);
  ensures \result == side * side;
  assigns \nothing;
*/
int32_t square_area(int32_t side) {
    int32_t ret;
    //@ assert side * side <= 46340 * 46340;
    ret = side * side;
    return ret;
}

int main() {
    int32_t side_length;
    int32_t n;
    
    side_length = 5;
    n = square_area(side_length);
    //@ assert n == 25;
    return 0;
}
