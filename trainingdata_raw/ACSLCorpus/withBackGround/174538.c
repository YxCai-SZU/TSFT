/*@
    logic integer square_area(integer side) =
        side < 0 ? 0 : side * side;

    lemma square_area_nonneg:
        \forall integer side; square_area(side) >= 0;
*/

int main() {
    //@ assert square_area(5) == 25;
    //@ assert square_area(-3) == 0;
    //@ assert square_area(0) == 0;
    return 0;
}
