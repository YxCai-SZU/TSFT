#include <stdint.h>

/*@
    predicate commutative_and(integer a, integer b) =
        (a & b) == (b & a);
    predicate commutative_or(integer a, integer b) =
        (a | b) == (b | a);
    predicate commutative_xor(integer a, integer b) =
        (a ^ b) == (b ^ a);
    predicate self_and_one(integer a) =
        (a & 1) == (a & 1);
*/

/*@
    requires \true;
    ensures commutative_and(a, b);
    ensures commutative_or(a, b);
    ensures commutative_xor(a, b);
    ensures self_and_one(a);
*/
void test_bitwise_properties(uint32_t a, uint32_t b) {
    // Variable declarations at top of scope
    uint32_t and_result1;
    uint32_t and_result2;
    uint32_t or_result1;
    uint32_t or_result2;
    uint32_t xor_result1;
    uint32_t xor_result2;
    uint32_t and_one_result1;
    uint32_t and_one_result2;
    
    //@ assert commutative_and(a, b);
    and_result1 = a & b;
    and_result2 = b & a;
    
    //@ assert commutative_or(a, b);
    or_result1 = a | b;
    or_result2 = b | a;
    
    //@ assert commutative_xor(a, b);
    xor_result1 = a ^ b;
    xor_result2 = b ^ a;
    
    //@ assert self_and_one(a);
    and_one_result1 = a & 1;
    and_one_result2 = a & 1;
}

int main() {
    return 0;
}
