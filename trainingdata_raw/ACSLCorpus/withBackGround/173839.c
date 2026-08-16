/*@
    predicate is_in_range(integer v) = 0 <= v && v <= 1;

    lemma mul_is_associative:
        \forall integer x, y, z;
            is_in_range(x) && is_in_range(y) && is_in_range(z) ==>
            (x * y) * z == x * (y * z);

    lemma mul_is_distributive_add:
        \forall integer x, y, z;
            is_in_range(x) && is_in_range(y) && is_in_range(z) ==>
            x * (y + z) == x * y + x * z;
*/

/*@
    requires 0 <= x && x <= 1;
    requires 0 <= y && y <= 1;
    requires 0 <= z && z <= 1;
    ensures \result == ((x * y) * z == x * (y * z));
    assigns \nothing;
*/
int verify_mul_is_associative(int x, int y, int z) {
    //@ assert is_in_range(x) && is_in_range(y) && is_in_range(z);
    return (x * y) * z == x * (y * z);
}

/*@
    requires 0 <= x && x <= 1;
    requires 0 <= y && y <= 1;
    requires 0 <= z && z <= 1;
    ensures \result == (x * (y + z) == x * y + x * z);
    assigns \nothing;
*/
int verify_mul_is_distributive_add(int x, int y, int z) {
    //@ assert is_in_range(x) && is_in_range(y) && is_in_range(z);
    return x * (y + z) == x * y + x * z;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
