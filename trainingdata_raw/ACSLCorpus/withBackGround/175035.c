#include <stdint.h>

/*@ predicate valid_range(integer a, integer b) =
        1 <= a && a <= b && b <= 100;
*/

/*@ logic integer diff(integer a, integer b) = b - a; */

/*@ logic integer calc_price(integer d) = d * 5; */

/*@ lemma diff_nonnegative:
        \forall integer a, b; valid_range(a, b) ==> diff(a, b) >= 0;
*/

/*@ lemma price_nonnegative:
        \forall integer a, b; valid_range(a, b) ==> calc_price(diff(a, b)) >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (uint64_t)\result * 8 / 100 == a && (uint64_t)\result * 10 / 100 == b;
*/
int64_t func(uint64_t a, uint64_t b) {
    uint64_t diff = b - a;
    uint64_t price = diff * 5;
    uint64_t x = 0;
    uint64_t temp_price = price;

    /*@
        loop invariant 1 <= a && a <= b && b <= 100;
        loop invariant 0 <= x;
        loop invariant temp_price <= diff * 5;
        loop invariant temp_price >= 0;
        loop invariant x * 8 + temp_price == diff * 5;
        loop assigns temp_price, x;
        loop variant temp_price;
    */
    while (temp_price >= 8) {
        //@ assert temp_price >= 8;
        temp_price -= 8;
        x += 1;
    }
    price = x;

    x = 0;
    temp_price = diff * 5;

    /*@
        loop invariant 1 <= a && a <= b && b <= 100;
        loop invariant 0 <= x;
        loop invariant temp_price <= diff * 5;
        loop invariant temp_price >= 0;
        loop invariant x * 10 + temp_price == diff * 5;
        loop assigns temp_price, x;
        loop variant temp_price;
    */
    while (temp_price >= 10) {
        //@ assert temp_price >= 10;
        temp_price -= 10;
        x += 1;
    }

    if (price == a && x == b) {
        return (int64_t)(price * 8);
    } else {
        return -1;
    }
}
