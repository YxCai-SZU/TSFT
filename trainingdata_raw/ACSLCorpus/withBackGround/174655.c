/*@
    logic integer my_mod(integer x, integer y) = x % y;

    lemma test_mod:
        my_mod(17, 5) == 2 &&
        my_mod(10, 3) == 1;

    logic integer double_val(integer x) = x * 2;

    lemma double_proof:
        \forall integer x; x >= 0 && x <= 0x40000000 ==> double_val(x) == x + x;

    logic integer square(integer x) = x * x;

    lemma square_proof:
        \forall integer x; x >= 0 && x <= 0x40000000 ==> square(x) == x * x;

    logic integer volume_cube(integer side) = side * side * side;

    lemma cube_volume_proof:
        \forall integer side; side >= 0 && side <= 5 ==> volume_cube(side) == side * side * side;
*/

int main() {
    return 0;
}
