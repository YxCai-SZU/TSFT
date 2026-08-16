/*@
    predicate bounds(integer x, integer y) = 0 <= x <= 10 && 0 <= y <= 20;
    predicate mul_le_200(integer x, integer y) = x * y <= 200;
    predicate mul_lt_300(integer x, integer y) = x * y < 300;
    predicate mul_eq(integer x, integer y) = x * y == x * y;
    predicate mul_distributive(integer x, integer y, integer z) = x * (y + z) == x * y + x * z;
    predicate mul_associative(integer x, integer y, integer z) = x * (y * z) == (x * y) * z;

    lemma upper_bound: \forall integer x, y; bounds(x, y) ==> mul_le_200(x, y);
    lemma strict_upper_bound: \forall integer x, y; bounds(x, y) ==> mul_lt_300(x, y);
    lemma nonlinear_arith: \forall integer x, y; bounds(x, y) ==> mul_eq(x, y);
    lemma mul_is_distributive_add: \forall integer x, y, z; bounds(x, y) && 0 <= z <= 10 ==> mul_distributive(x, y, z);
    lemma mul_is_associative: \forall integer x, y, z; bounds(x, y) && 0 <= z <= 10 ==> mul_associative(x, y, z);
*/

#include <stdbool.h>

/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 20;
    ensures \result == (x * y <= 200);
    assigns \nothing;
*/
bool verify_nonlinear_arith(unsigned int x, unsigned int y) {
    //@ assert bounds(x, y);
    //@ assert mul_le_200(x, y);
    return x * y <= 200;
}
