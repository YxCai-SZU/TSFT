/*@
predicate mul_distributive_pre(integer x, integer y, integer z) =
    x * y <= 2147483647 &&
    y * z <= 2147483647 &&
    x * (y + z) <= 2147483647;

lemma mul_is_distributive_add:
    \forall integer x, y, z;
    mul_distributive_pre(x, y, z) ==>
    x * (y + z) == x * y + x * z;
*/

int main() {
    return 0;
}
