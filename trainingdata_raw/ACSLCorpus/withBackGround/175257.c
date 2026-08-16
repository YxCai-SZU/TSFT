/*@
    logic integer incrementor(integer x, integer k) = k + x;
    lemma test_incrementor:
        incrementor(7, 3) == 10 && incrementor(7, 0) == 7;

    logic integer double_value(integer a, integer k) = k * 2;
    lemma test_double_value:
        double_value(5, 3) == 6 && double_value(5, 4) == 8;

    logic integer add_and_double(integer a, integer b) = (a + b) * 2;
    lemma test_add_and_double:
        add_and_double(2, 3) == 10 && add_and_double(-1, 5) == 8;

    logic integer square_number(integer x, integer k) = k * k;
    lemma test_square_number:
        square_number(4, 3) == 9 && square_number(4, 5) == 25;

    logic integer cube_number(integer x, integer k) = k * k * k;
    lemma test_cube_number:
        cube_number(3, 2) == 8 && cube_number(3, 4) == 64;
*/

int main() {
    return 0;
}
