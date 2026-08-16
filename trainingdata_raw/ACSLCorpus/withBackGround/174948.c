/*@
    predicate is_safe_div(integer a, integer b) =
        a >= 0 && b > 0 && a <= 2000000000000 && b <= 1000;

    predicate is_small_div(integer a, integer b) =
        a >= 0 && b > 0 && a <= 1000 && b <= 1000;

    lemma test_truncating_div:
        \forall integer a, b; is_safe_div(a, b) ==> a / b == (integer)(a / b);

    lemma test_div_on_u64:
        \forall integer a, b; is_small_div(a, b) ==> a / b == (integer)(a / b);

    lemma test_div_equivalent_to_bit_vector_div:
        \forall integer a, b; is_small_div(a, b) ==> a / b == (integer)(a / b);
*/

#include <stdint.h>

int main()
{
    uint64_t a;
    uint64_t b;
    
    return 0;
}
