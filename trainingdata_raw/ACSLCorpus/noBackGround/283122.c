#include <stdint.h>

/*@
    requires a > b;
    requires b >= c;
    ensures \result == 1;
*/
uint8_t verify_calc_example_4(uint8_t a, uint8_t b, uint8_t c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a >= c;
    return 1;
}

/*@
    requires a > b;
    requires b > c;
    ensures \result == 1;
*/
uint8_t verify_calc_example_5(uint8_t a, uint8_t b, uint8_t c) {
    //@ assert a > b;
    //@ assert b > c;
    //@ assert a > c;
    return 1;
}

/*@
    requires a >= b;
    requires b > c;
    ensures \result == 1;
*/
uint8_t verify_calc_example_6(uint8_t a, uint8_t b, uint8_t c) {
    //@ assert a >= b;
    //@ assert b > c;
    //@ assert a > c;
    return 1;
}

/*@
    requires a > b;
    requires b >= c;
    ensures \result == 1;
*/
uint8_t verify_calc_example_7(uint8_t a, uint8_t b, uint8_t c) {
    //@ assert a > b;
    //@ assert b >= c;
    //@ assert a > c;
    return 1;
}

int main() {
    return 0;
}
