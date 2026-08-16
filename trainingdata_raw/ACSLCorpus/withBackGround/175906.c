/*@
    predicate equal_bits(integer a, integer b) = (a & 1) == (b & 1);
    
    lemma test_proof: \forall integer a, b; a == b ==> equal_bits(a, b);
    
    lemma assert_test: \forall integer a, b; a == b ==> a == b && equal_bits(a, b);
*/

#include <stdint.h>

/*@
    requires a == b;
    ensures (a & 0x1) == (b & 0x1);
*/
void test_proof_c(uint32_t a, uint32_t b)
{
    //@ assert a == b;
    //@ assert (a & 0x1) == (b & 0x1);
}

/*@
    requires a == b;
    ensures \true;
*/
void assert_test_c(uint32_t a, uint32_t b)
{
    //@ assert a == b;
    //@ assert (a & 0x1) == (b & 0x1);
}

int main() {
    return 0;
}
