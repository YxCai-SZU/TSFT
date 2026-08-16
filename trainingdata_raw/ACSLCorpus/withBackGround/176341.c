/*@
    logic integer abs_value(integer n) = (n >= 0) ? n : -n;

    lemma abs_value_positive:
        \forall integer i; i >= 0 ==> abs_value(i) == i;

    lemma abs_value_exists:
        \exists integer i; abs_value(i) == 5;

    lemma abs_value_symmetric:
        \forall integer n; abs_value(-n) == abs_value(n);

    lemma abs_value_zero:
        abs_value(0) == 0;

    lemma abs_value_positive_example:
        abs_value(5) == 5;

    lemma abs_value_negative_example:
        abs_value(-5) == 5;

    lemma abs_value_equal_example:
        abs_value(-5) == abs_value(5);
*/

int main() {
    //@ assert abs_value(-10) == 10;
    //@ assert abs_value(5) == 5;
    return 0;
}
