#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result <= 100;
*/
uint32_t calc_nonlinear(uint32_t a, uint32_t b) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert a * b <= 100;
    return a * b;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result <= 20;
*/
uint32_t calc_add(uint32_t a, uint32_t b) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert a + b <= 20;
    return a + b;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    requires 1 <= c && c <= 10;
    ensures \result <= 100;
*/
uint32_t calc_mul_leq(uint32_t a, uint32_t b, uint32_t c) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert (1 <= (c) && (c) <= 10);
    //@ assert a * b <= 100;
    return a * b;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    requires 1 <= c && c <= 10;
    ensures \result <= 1000;
*/
uint32_t calc_mul(uint32_t a, uint32_t b, uint32_t c) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert (1 <= (c) && (c) <= 10);
    //@ assert a * b * c <= 1000;
    return a * b * c;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result <= 10;
*/
uint32_t calc_modulo(uint32_t a, uint32_t b) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert a % b <= 10;
    return a % b;
}

/*@
    requires 1 <= a && a <= 10;
    requires 1 <= b && b <= 10;
    ensures \result >= 0;
*/
uint32_t calc_modulo2(uint32_t a, uint32_t b) {
    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert a % b >= 0;
    return a % b;
}

int main() {
    return 0;
}
