#include <stdint.h>

/*@
    predicate non_zero_and(uint32_t x, uint32_t y) = (x & y) != 0;

    lemma and_non_zero_lemma:
        \forall uint32_t x, y; non_zero_and(x, y) ==> (x & y) != 0;
*/

/*@
    requires non_zero_and(x, y);
    ensures \result == (x & y);
    assigns \nothing;
*/
uint32_t bitwise_and_not_zero(uint32_t x, uint32_t y) {
    //@ assert non_zero_and(x, y);
    return x & y;
}

int main() {
    return 0;
}
