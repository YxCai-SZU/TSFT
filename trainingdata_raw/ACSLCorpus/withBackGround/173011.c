/*@
    logic integer multiplier(integer x, integer k) = k * x;
*/

/*@
    lemma test_multiplier:
        multiplier(4, 10) == 40 &&
        multiplier(4, 3) == 12;
*/

/*@
    lemma multiplier_postconditions:
        \forall integer x, k; x >= 0 && k >= 0 ==> multiplier(x, k) == x * k;
*/

/*@
    lemma test_multiplier_2:
        multiplier(3, 5) == 15 &&
        multiplier(3, 9) == 27;
*/

/*@
    lemma test_multiplier_3:
        multiplier(2, 7) == 14 &&
        multiplier(2, 8) == 16;
*/

/*@
    lemma test_multiplier_4:
        multiplier(1, 3) == 3 &&
        multiplier(1, 6) == 6;
*/

/*@
    lemma test_multiplier_5:
        multiplier(0, 4) == 0 &&
        multiplier(0, 9) == 0;
*/

int main() {
    return 0;
}
