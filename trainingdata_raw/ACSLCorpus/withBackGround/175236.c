/*@
    logic integer multiplier(integer x, integer k) = k * x;

    lemma test_multiplier:
        multiplier(4, 5) == 20 &&
        multiplier(4, 6) == 24 &&
        multiplier(4, 10) == 40;

    logic integer square(integer x, integer k) = k * k;

    lemma test_square:
        square(3, 4) == 16 &&
        square(3, 6) == 36 &&
        square(3, 10) == 100;

    logic integer exponent(integer x, integer k) = x * x;

    lemma test_exponent:
        exponent(3, 4) == 9 &&
        exponent(3, 6) == 9 &&
        exponent(3, 10) == 9;

    logic integer decrementor(integer x, integer k) = k - x;

    lemma test_decrementor:
        decrementor(4, 10) == 6 &&
        decrementor(4, 3) == -1 &&
        decrementor(4, 20) == 16;

    lemma property_decrementor:
        \forall integer x, k; 0 <= x && 0 <= k ==> decrementor(x, k) <= k;

    lemma property_multiplier:
        \forall integer x, k; 0 <= x && 0 <= k ==> multiplier(x, k) <= k * x;

    lemma property_square:
        \forall integer x, k; 0 <= x && 0 <= k ==> square(x, k) <= k * k;

    lemma property_exponent:
        \forall integer x, k; 0 <= x && 0 <= k ==> exponent(x, k) <= x * x;
*/

int main() {
    return 0;
}
