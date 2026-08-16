/*@
    predicate side_nonnegative(integer side) = side >= 0;
    predicate side_safe(integer side) = side * side * side < 0x100000000;

    logic integer volume_cube(integer side) =
        side <= 0 ? 0 : side * side * side;

    lemma volume_cube_nonneg:
        \forall integer n; n >= 0 ==> volume_cube(n) >= 0;
*/

int main() {
    //@ assert volume_cube(0) == 0;
    return 0;
}
