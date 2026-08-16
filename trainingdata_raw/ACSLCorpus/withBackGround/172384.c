#include <stdint.h>

/*@
    predicate is_positive(integer x) = x >= 1;

    lemma verify_no_leading_zeroes_u32:
        \forall integer x; is_positive(x) ==> (x / 2) / 2 == x / 4;

    lemma verify_no_leading_zeroes_u32_2:
        \forall integer x, y; is_positive(x) && is_positive(y) ==> (x * y) / 2 == (x * y) / 2;

    lemma verify_mul_is_distributive:
        \forall integer x, y, z; is_positive(x) && is_positive(y) && is_positive(z) ==> x * (y + z) == x * y + x * z;

    lemma verify_mul_is_associative:
        \forall integer x, y, z; is_positive(x) && is_positive(y) && is_positive(z) ==> (x * y) * z == x * (y * z);

    lemma verify_no_leading_zeroes_mul_is_commutative:
        \forall integer x, y; is_positive(x) && is_positive(y) ==> x * y == y * x;

    lemma verify_no_leading_zeroes_mul_is_distributive_add:
        \forall integer x, y, z; is_positive(x) && is_positive(y) && is_positive(z) ==> x * (y + z) == x * y + x * z;
*/

int main() {
    return 0;
}
