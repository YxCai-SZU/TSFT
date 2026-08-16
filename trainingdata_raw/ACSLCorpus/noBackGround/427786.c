#include <stdint.h>

/*@
    requires 0 <= x <= 4294967295;
    requires 0 <= y <= 4294967295;
    ensures \result <= 18446744065119617025;
    assigns \nothing;
*/
uint64_t verify_mul_upper_bound(uint32_t x, uint32_t y) {
    uint64_t result;
    result = (uint64_t)x * (uint64_t)y;
    //@ assert result <= 18446744065119617025;
    return result;
}

/*@
    requires 0 <= x <= 4294967295;
    requires 0 <= y <= 4294967295;
    requires 0 <= z <= 4294967295;
    ensures \result <= 18446744069414584320;
    assigns \nothing;
*/
uint64_t verify_nonlinear_arith(uint32_t x, uint32_t y, uint32_t z) {
    uint64_t result;
    result = (uint64_t)x * (uint64_t)y + (uint64_t)z;
    //@ assert result <= 18446744069414584320;
    return result;
}

/*@
    requires 0 <= x <= 4294967295;
    requires 0 <= y <= 4294967295;
    requires 0 <= z <= 4294967295;
    ensures \result <= 79228162514264337593543950335;
    assigns \nothing;
*/
uint64_t verify_nonlinear_arith2(uint32_t x, uint32_t y, uint32_t z) {
    uint64_t result;
    result = (uint64_t)x * (uint64_t)y * (uint64_t)z;
    //@ assert result <= 79228162514264337593543950335;
    return result;
}

/*@
    requires 0 <= x <= 4294967295;
    requires 0 <= y <= 4294967295;
    requires 0 <= z <= 4294967295;
    ensures \result <= 79228162514264337593543950335;
    assigns \nothing;
*/
uint64_t verify_nonlinear_arith3(uint32_t x, uint32_t y, uint32_t z) {
    uint64_t intermediate;
    uint64_t result;
    intermediate = (uint64_t)x * (uint64_t)y;
    //@ assert intermediate <= 18446744065119617025;
    result = intermediate * (uint64_t)z;
    //@ assert result <= 79228162514264337593543950335;
    return result;
}

/*@
    requires 0 <= x <= 4294967295;
    requires 0 <= y <= 4294967295;
    requires 0 <= z <= 4294967295;
    requires 0 <= w <= 4294967295;
    ensures \result <= 340282366920938463426481119284349108225;
    assigns \nothing;
*/
uint64_t verify_nonlinear_arith4(uint32_t x, uint32_t y, uint32_t z, uint32_t w) {
    uint64_t intermediate1;
    uint64_t intermediate2;
    uint64_t result;
    intermediate1 = (uint64_t)x * (uint64_t)y;
    //@ assert intermediate1 <= 18446744065119617025;
    intermediate2 = intermediate1 * (uint64_t)z;
    //@ assert intermediate2 <= 79228162514264337593543950335;
    result = intermediate2 * (uint64_t)w;
    //@ assert result <= 340282366920938463426481119284349108225;
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
