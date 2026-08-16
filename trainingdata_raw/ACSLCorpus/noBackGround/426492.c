#include <stdint.h>

void main() {
    // Empty main function as per original Rust code
}

/*@ requires 0 <= x <= 30 && 0 <= y <= 3;
    ensures \result <= 90;
    assigns \nothing; */
uint32_t safe_multiplication(uint32_t x, uint32_t y) {
    uint32_t result;
    result = x * y;
    
    //@ assert ((x) <= 30 && (y) <= 3 ==> (x) * (y) <= 90);
    
    return result;
}

/*@ requires 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    ensures \result == x * y + x * z;
    assigns \nothing; */
uint32_t distributive_multiplication(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t left_side;
    uint32_t right_side;
    
    left_side = x * (y + z);
    right_side = x * y + x * z;
    
    //@ assert ((x) <= 10 && (y) <= 10 && (z) <= 10 ==> (x) * ((y) + (z)) == (x) * (y) + (x) * (z));
    
    return left_side;
}

/*@ requires 0 <= x <= 10 && 0 <= y <= 10 && 0 <= z <= 10;
    ensures \result == (x * y) * z;
    assigns \nothing; */
uint32_t associative_multiplication(uint32_t x, uint32_t y, uint32_t z) {
    uint32_t left_grouping;
    uint32_t right_grouping;
    
    left_grouping = x * (y * z);
    right_grouping = (x * y) * z;
    
    //@ assert ((x) <= 10 && (y) <= 10 && (z) <= 10 ==> (x) * ((y) * (z)) == ((x) * (y)) * (z));
    
    return left_grouping;
}
