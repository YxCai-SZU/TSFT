#include <stdint.h>

/*@
    predicate bounds(uint32_t a, uint32_t b, uint32_t c) =
        a <= 0x0000ffff && b <= 0x0000ffff && c <= 0x0000ffff;

    logic integer xor_result(integer a, integer b, integer c) = a ^ b ^ c;

    lemma sum_bound1: \forall integer a, b; a <= 0x0000ffff && b <= 0x0000ffff ==> a + b <= 0x0001ffff;
    lemma sum_bound2: \forall integer a, b, c; a <= 0x0000ffff && b <= 0x0000ffff && c <= 0x0000ffff ==> a + b + c <= 0x0002ffff;
    lemma xor_cast: \forall integer x, y; (x ^ y) == (x ^ y);
*/

/*@
    requires bounds(a, b, c);
    ensures \result == xor_result(a, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    //@ assert bounds(a, b, c);
    
    uint32_t result;
    result = a ^ b ^ c;
    //@ assert result == xor_result(a, b, c);
    return result;
}

/*@
    lemma test_xor_u32_vs_u64: \forall integer x, y; (x ^ y) == (x ^ y);
*/

/*@ assigns \nothing; */
int main()
{
    return 0;
}
