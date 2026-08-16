/*@
    logic integer abs_value(integer n) = (n >= 0) ? n : -n;

    lemma test_abs_value_pos: \forall integer x; x >= 0 ==> abs_value(x) == x;
    lemma test_abs_value_neg: \forall integer x; x < 0 ==> abs_value(x) == -x;

    logic integer min_value(integer a, integer b) = (a <= b) ? a : b;

    lemma test_min_value_a_le_b: \forall integer a, b; a <= b ==> min_value(a, b) == a;
    lemma test_min_value_b_le_a: \forall integer a, b; b < a ==> min_value(a, b) == b;

    logic integer max_value(integer a, integer b) = (a >= b) ? a : b;

    lemma test_max_value_a_ge_b: \forall integer a, b; a >= b ==> max_value(a, b) == a;
    lemma test_max_value_b_ge_a: \forall integer a, b; b > a ==> max_value(a, b) == b;

    predicate is_even(integer n) = (n % 2) == 0;

    lemma test_is_even_pos: \forall integer n; (n % 2) == 0 ==> is_even(n);
    lemma test_is_even_neg: \forall integer n; (n % 2) != 0 ==> !is_even(n);

    predicate is_odd(integer n) = (n % 2) != 0;

    lemma test_is_odd_pos: \forall integer n; (n % 2) != 0 ==> is_odd(n);
    lemma test_is_odd_neg: \forall integer n; (n % 2) == 0 ==> !is_odd(n);
*/

#include <limits.h>

/*@
    requires n > INT_MIN;
    ensures \result == abs_value(n);
    assigns \nothing;
*/
int abs_value_c(int n) {
    int result;
    //@ assert n > INT_MIN;
    if (n >= 0) {
        result = n;
    } else {
        result = -n;
    }
    //@ assert result == abs_value(n);
    return result;
}

int main() {
    int a;
    int b;

    a = abs_value_c(-10);
    //@ assert a == 10;

    b = abs_value_c(5);
    //@ assert b == 5;

    return 0;
}
