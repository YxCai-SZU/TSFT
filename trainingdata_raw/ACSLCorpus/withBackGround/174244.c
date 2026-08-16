/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_positive(integer x) = x > 0;
    predicate is_bounded(integer x, integer bound) = 0 <= x <= bound;

    lemma add_is_associative:
        \forall integer x, y, z; (x + y) + z == x + (y + z);

    lemma add_is_commutative:
        \forall integer x, y; x + y == y + x;

    lemma mul_is_associative:
        \forall integer x, y, z; (x * y) * z == x * (y * z);

    lemma mul_is_commutative:
        \forall integer x, y; x * y == y * x;

    lemma mul_is_distributive_add:
        \forall integer x, y, z; x * (y + z) == x * y + x * z;

    lemma mul_is_distributive_mul:
        \forall integer x, y, z; x * (y * z) == x * y * z;

    lemma mul_no_negative:
        \forall integer x, y; is_nonnegative(x) && is_nonnegative(y) ==> is_nonnegative(x * y);

    lemma mul_no_negative_strict:
        \forall integer x, y; is_positive(x) && is_positive(y) ==> is_positive(x * y);
*/

/*@
    requires \true;
    assigns \nothing;
*/
int main() {
    return 0;
}
