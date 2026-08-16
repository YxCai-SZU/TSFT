#include <stdint.h>

/*@
    predicate in_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer safe_product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; in_range(a, b) ==> safe_product(a, b) <= 10000;
*/

/*@
    requires in_range(a, b);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t c;
    int32_t result;
    uint32_t temp_c;
    uint32_t count;

    //@ assert in_range(a, b);
    //@ assert safe_product(a, b) <= 10000;

    c = a * b;
    result = 0;
    temp_c = c;
    count = 0;

    /*@
        loop invariant 0 <= temp_c && temp_c <= c;
        loop invariant 0 <= count && count <= c / 2;
        loop invariant temp_c + 2 * count == c;
        loop assigns temp_c, count;
        loop variant temp_c;
    */
    while (temp_c >= 2) {
        temp_c -= 2;
        count += 1;
    }

    result = (int32_t)count;
    //@ assert result == (a * b) / 2;
    return result;
}
