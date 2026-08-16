#include <stdint.h>

/*@
    predicate bitwise_and_commutes(integer x, integer y) = (x & y) == (y & x);
    predicate bitwise_or_commutes(integer x, integer y) = (x | y) == (y | x);
    predicate bitwise_xor_commutes(integer x, integer y) = (x ^ y) == (y ^ x);
*/

/*@
    lemma bitwise_and_commutes_lemma: \forall integer x, y; bitwise_and_commutes(x, y);
    lemma bitwise_or_commutes_lemma: \forall integer x, y; bitwise_or_commutes(x, y);
    lemma bitwise_xor_commutes_lemma: \forall integer x, y; bitwise_xor_commutes(x, y);
*/

/*@
    requires 0 <= a <= UINT32_MAX && 0 <= b <= UINT32_MAX;
    assigns \nothing;
    ensures \result == (a & b);
*/
uint32_t test_bitwise_and(uint32_t a, uint32_t b) {
    uint32_t result;
    result = a & b;
    //@ assert result == (a & b);
    return result;
}

/*@
    requires 0 <= a <= UINT32_MAX && 0 <= b <= UINT32_MAX;
    assigns \nothing;
    ensures \result == (a | b);
*/
uint32_t test_bitwise_or(uint32_t a, uint32_t b) {
    uint32_t result;
    result = a | b;
    //@ assert result == (a | b);
    return result;
}

/*@
    requires 0 <= a <= UINT32_MAX && 0 <= b <= UINT32_MAX;
    assigns \nothing;
    ensures \result == (a ^ b);
*/
uint32_t test_bitwise_xor(uint32_t a, uint32_t b) {
    uint32_t result;
    result = a ^ b;
    //@ assert result == (a ^ b);
    return result;
}

/*@
    requires 0 <= a <= UINT32_MAX;
    assigns \nothing;
    ensures \result == (unsigned)(~a);
*/
uint32_t test_bitwise_not(uint32_t a) {
    uint32_t result;
    result = ~a;
    //@ assert result == (unsigned)(~a);
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
