#include <stdint.h>

/*@
    requires x <= 1000 && y <= 1000;
    ensures \result <= 1000000;
*/
uint32_t assert_mul_bound(uint32_t x, uint32_t y) {
    //@ assert ((x) <= 1000 && (y) <= 1000 ==> (x) * (y) <= 1000000);
    return x * y;
}

/*@
    requires x > 0 && y > 0;
    ensures \result >= 0;
*/
int assert_division_remainder(int x, int y) {
    //@ assert ((x) > 0 && (y) > 0 ==> (x) % (y) >= 0);
    return x % y;
}

/*@
    requires x <= 100 && y <= 100 && z <= 100;
    ensures *out1 <= 10000 && *out2 <= 10000 && *out3 <= 10000;
*/
void assert_multiplication_bound_check(uint32_t x, uint32_t y, uint32_t z,
                                       uint32_t *out1, uint32_t *out2, uint32_t *out3) {
    //@ assert ((x) <= 100 && (y) <= 100 && (z) <= 100 ==>             (x) * (y) <= 10000 && (y) * (z) <= 10000 && (x) * (z) <= 10000);
    *out1 = x * y;
    *out2 = y * z;
    *out3 = x * z;
}

/*@
    requires x <= 1000 && y <= 1000 && z <= 1000;
    ensures *out1 <= 1000000 && *out2 <= 2000 && *out3 <= 2000;
*/
void assert_all(uint32_t x, uint32_t y, uint32_t z,
                uint32_t *out1, uint32_t *out2, uint32_t *out3) {
    //@ assert ((x) <= 1000 && (y) <= 1000 && (z) <= 1000 ==>             (x) * (y) <= 1000000 && (x) + (y) <= 2000 && (x) + (z) <= 2000);
    *out1 = x * y;
    *out2 = x + y;
    *out3 = x + z;
}

int main() {
    return 0;
}
