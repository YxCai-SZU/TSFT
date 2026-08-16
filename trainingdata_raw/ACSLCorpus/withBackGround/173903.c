#include <stdint.h>

/*@
    predicate bounds(uint32_t x, uint32_t y, uint32_t z) =
        x <= 10 && y <= 10 && z <= 10;

    lemma product_bound:
        \forall uint32_t x, y, z;
            bounds(x, y, z) ==> x * y <= 100;

    lemma triple_product_bound:
        \forall uint32_t x, y, z;
            bounds(x, y, z) ==> x * y * z <= 1000;
*/

/*@
    requires \true;
    ensures \result == 0;
    assigns \nothing;
*/
int main() {
    uint32_t x;
    uint32_t y;
    uint32_t z;
    int result = 0;

    //@ assert x <= 10 && y <= 10 && z <= 10 ==> x * y <= 100;
    //@ assert x <= 10 && y <= 10 && z <= 10 ==> x * y * z <= 1000;

    return result;
}
