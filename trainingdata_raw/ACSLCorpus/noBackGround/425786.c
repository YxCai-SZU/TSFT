#include <stdint.h>

/*@
    requires 1 <= x && x <= 5;
    requires 1 <= y && y <= 10;
    requires 1 <= z && z <= 15;
    ensures \result == 1;
*/
int assert_relation_wrapper(int x, int y, int z) {
    //@ assert 1 <= x && x <= 5;
    //@ assert 1 <= y && y <= 10;
    //@ assert 1 <= z && z <= 15;
    //@ assert x * y * z <= 750;
    return 1;
}

/*@
    requires x <= 8;
    requires y <= 8;
    ensures \result == 1;
*/
int bound_check_wrapper(uint32_t x, uint32_t y) {
    //@ assert x * y <= 1000;
    return 1;
}

int main() {
    return 0;
}
