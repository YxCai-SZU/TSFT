/*@
    predicate is_greater_or_equal(integer a, integer b) = a >= b;
    predicate is_less_than(integer a, integer b) = a < b;
    logic integer plus_one(integer n) = n + 1;

    lemma greater_than_or_equal_lemma:
        \forall integer a, b; is_greater_or_equal(a, b) ==> a >= b;
    lemma less_than_lemma:
        \forall integer a, b; is_less_than(a, b) ==> a < b;
    lemma inequality_lemma:
        \forall integer n; n < plus_one(n);
*/

/*@
    requires n > 0;
    ensures \result == 0;
    ensures n < n + 2;
*/
int calc_example_6(int n) {
    //@ assert n > 0;
    //@ assert n < n + 1;
    //@ assert n + 1 <= n + 2;
    //@ assert n < n + 2;
    return 0;
}

int main() {
    return 0;
}
