#include <stdint.h>

/*@
    predicate is_valid_array(uint32_t* a, integer len) =
        len == 3 &&
        \valid(a + (0 .. 2)) &&
        a[0] < 10 && a[1] < 10 && a[2] < 10;

    logic integer expr1(integer a0, integer a1, integer a2) = a0 * 10 + a1 + a2;
    logic integer expr2(integer a0, integer a1, integer a2) = a0 + a1 * 10 + a2;
    logic integer expr3(integer a0, integer a1, integer a2) = a0 + a1 + a2 * 10;

    lemma expr1_bound: \forall integer a0, a1, a2;
        a0 < 10 && a1 < 10 && a2 < 10 ==> expr1(a0, a1, a2) < 1000;
    lemma expr2_bound: \forall integer a0, a1, a2;
        a0 < 10 && a1 < 10 && a2 < 10 ==> expr2(a0, a1, a2) < 1000;
    lemma expr3_bound: \forall integer a0, a1, a2;
        a0 < 10 && a1 < 10 && a2 < 10 ==> expr3(a0, a1, a2) < 1000;
*/

/*@
    requires is_valid_array(a, 3);
    ensures \result == expr1(a[0], a[1], a[2]) ||
            \result == expr2(a[0], a[1], a[2]) ||
            \result == expr3(a[0], a[1], a[2]);
    ensures \result < 1000;
    assigns \nothing;
*/
uint32_t func(uint32_t* a)
{
    //@ assert a[0] < 10 && a[1] < 10 && a[2] < 10;
    //@ assert expr1(a[0], a[1], a[2]) < 1000;
    //@ assert expr2(a[0], a[1], a[2]) < 1000;
    //@ assert expr3(a[0], a[1], a[2]) < 1000;

    uint32_t max_val;
    uint32_t temp_val;

    max_val = a[0] * 10 + a[1] + a[2];
    temp_val = a[0] + a[1] * 10 + a[2];
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    temp_val = a[0] + a[1] + a[2] * 10;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    return max_val;
}
