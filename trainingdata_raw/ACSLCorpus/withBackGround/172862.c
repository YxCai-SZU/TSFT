/*@
predicate positive(integer n) = n > 0;

lemma calculation_lemma:
    \forall integer n; positive(n) ==> 2 * n + 3 > n;
*/

/*@
    requires n > 0;
    ensures \result > n;
*/
int calculation_property(int n) {
    //@ assert n > 0;
    //@ assert n + 3 > 0;
    //@ assert 2 * n > 0;
    //@ assert 2 * n + 3 > 0;
    //@ assert 2 * n + 3 > n;
    return 2 * n + 3;
}

int main() {
    return 0;
}
