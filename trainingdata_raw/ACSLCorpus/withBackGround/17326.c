/*@
    logic integer abs_value(integer n) = (n >= 0) ? n : -n;

    predicate even(integer n) = n % 2 == 0;
    predicate odd(integer n) = n % 2 != 0;

    predicate abs_value_even(integer n) = even(abs_value(n));
    predicate abs_value_odd(integer n) = odd(abs_value(n));

    lemma proof_abs_value_even:
        \forall integer n; even(n) ==> abs_value_even(n);

    lemma proof_abs_value_odd:
        \forall integer n; odd(n) ==> abs_value_odd(n);

    lemma proof_abs_value_even_neg:
        \forall integer n; even(n) ==> abs_value_even(-n);

    lemma proof_abs_value_odd_neg:
        \forall integer n; odd(n) ==> abs_value_odd(-n);
*/

int main() {
    return 0;
}
