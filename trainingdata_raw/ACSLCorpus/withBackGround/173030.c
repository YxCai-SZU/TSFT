/*@
    predicate non_negative(integer value) = value >= 0;

    lemma addition_lemma:
        \forall integer num1, num2;
            non_negative(num1) && non_negative(num2) ==> num1 + num2 >= num1;

    lemma subtraction_lemma:
        \forall integer num1, num2;
            non_negative(num1) && non_negative(num2) && num1 >= num2 ==> num1 - num2 >= 0;

    lemma calc_example_4_lemma:
        \forall integer x, y;
            x <= y ==> x + y <= y + y;

    lemma addition_incr_lemma:
        \forall integer num;
            non_negative(num) ==> num + 1 >= num;
*/

int main() {
    return 0;
}
