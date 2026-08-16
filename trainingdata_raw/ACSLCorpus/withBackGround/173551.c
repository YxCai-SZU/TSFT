/*@
    predicate greater_than(integer a, integer b) = a > b;

    lemma lemma_greater:
        \forall integer n; n > n - 2;

    lemma calc_example_10:
        \forall integer n; n >= 0 ==> n + 3 > n - 2;
*/

/*@
    requires n >= 0;
    ensures \result > n - 2;
*/
int calc_example_10(int n) {
    int result;
    //@ assert n >= 0;
    result = n + 3;
    //@ assert result > n - 2;
    return result;
}

int main() {
    int n = 5;
    int res = calc_example_10(n);
    return 0;
}
