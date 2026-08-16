/*@
    predicate is_odd(integer n) = n % 2 != 0;

    lemma is_odd_implies_not_even:
        \forall integer n; is_odd(n) ==> n % 2 != 0;
*/

/*@
    requires is_odd(n);
    ensures \result == 0;
*/
int example_odd_implies_not_even(int n) {
    //@ assert n % 2 != 0;
    return 0;
}

int main() {
    return 0;
}
